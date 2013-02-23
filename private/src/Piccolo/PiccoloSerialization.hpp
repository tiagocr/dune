//***************************************************************************
// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *
// Departamento de Engenharia Electrotécnica e de Computadores              *
// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *
//***************************************************************************
// Author: Ricardo Martins                                                  *
// Author: João Fortuna                                                     *
//***************************************************************************

#ifndef PICCOLO_SERIALIZATION_HPP_INCLUDED_
#define PICCOLO_SERIALIZATION_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <istream>
#include <vector>
#include <string>

// DUNE headers.
#include <DUNE/Utils/ByteCopy.hpp>
#include "PiccoloExceptions.hpp"
#include "PiccoloMessage.hpp"
#include "PiccoloFactory.hpp"

namespace Piccolo
{
  //! Retrieve the number of bytes required to serialize a variable
  //! of type 'plaintext'.
  //! @param[in] variable variable.
  //! @return number of bytes required to serialize variable.
  inline unsigned
  getSerializationSize(const std::string& variable)
  {
    return static_cast<unsigned>(variable.size()) + 2;
  }

  //! Retrieve the number of bytes required to serialize a variable
  //! of type 'rawdata'.
  //! @param[in] variable variable.
  //! @return number of bytes required to serialize variable.
  inline unsigned
  getSerializationSize(const std::vector<char>& variable)
  {
    return static_cast<unsigned>(variable.size()) + 2;
  }

  //! Serializator for scalar types.
  //! @param t scalar to serialize.
  //! @param bfr buffer where to place the serialized bytes.
  //! @return number of serialized bytes.
  template <typename Type>
  inline uint16_t
  serialize(const Type t, uint8_t* bfr)
  {
    uint16_t size = sizeof(Type);
    std::memcpy(bfr, &t, size);
    return size;
  }

  //! Serializator for floating point (double precision).
  //! @param t floating point value to serialize.
  //! @param bfr buffer where to place the serialized bytes.
  //! @return number of serialized bytes.
  inline uint16_t
  serialize(const fp64_t t, uint8_t* bfr)
  {
#if defined(DUNE_CPU_MIXED_ENDIAN_DOUBLES)
    uint8_t tmp[8];
    std::memcpy(tmp, &t, 8);

    bfr[0] = tmp[4];
    bfr[1] = tmp[5];
    bfr[2] = tmp[6];
    bfr[3] = tmp[7];
    bfr[4] = tmp[0];
    bfr[5] = tmp[1];
    bfr[6] = tmp[2];
    bfr[7] = tmp[3];
#else
  std::memcpy(bfr, &t, 8);
#endif
  return 8;
  }

  //! Serializator for scalar types.
  //! @param t scalar to serialize.
  //! @param bfr buffer where to place the serialized bytes.
  //! @return number of serialized bytes.
  template <typename Type>
  inline uint16_t
  reverseSerialize(const Type t, uint8_t* bfr, int size)
  {
    uint8_t tmp[8];
    uint8_t reversed[8];

    std::memcpy(tmp, &t, size);

    for(int i = 0; i < size; i++)
    {
      reversed[i] = tmp[size-i-1];
    }

    std::memcpy(bfr, reversed, size);
    return size;
  }

  //! Deserialize a numeric field with a different byte.
  //! @param t variable where to place the unserialized result.
  //! @param bfr buffer where to read the serialized bytes.
  //! @param length amount of bytes available to unserialize.
  //! @return number of serialized bytes.
  //! @throw BufferTooShort
  template <typename Type>
  inline uint16_t
  reverseDeserialize(Type& t, const uint8_t* bfr,  int size)
  {
    uint8_t reversed[8];

    for(int i = 0; i < size; i++)
    {
      reversed[i] = bfr[size-i-1];
    }

    std::memcpy(&t, reversed, size);

    return size;
  }
}

#endif
