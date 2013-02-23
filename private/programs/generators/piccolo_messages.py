# -*- coding: utf-8 -*-
############################################################################
# Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática #
# Departamento de Engenharia Electrotécnica e de Computadores              #
# Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          #
############################################################################
# Author: Joao Fortuna                                                     #
############################################################################

import sys
import os.path
import xml.etree.ElementTree as ET

tree = ET.parse(sys.argv[1])
folder = sys.argv[2]

desthpp = open(os.path.join(folder, 'PiccoloDefinitions.hpp'),'w')
destcpp = open(os.path.join(folder, 'PiccoloDefinitions.cpp'),'w')

root = tree.getroot()

polling_id = 0
dgps_id = 256
pilot_id = 512
ap_id = 768
gs_id = 1024
gimbal_id = 1280
message_id = 0

desthpp.write('//***************************************************************************\n')
desthpp.write('// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *\n')
desthpp.write('// Departamento de Engenharia Electrotécnica e de Computadores              *\n')
desthpp.write('// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *\n')
desthpp.write('//***************************************************************************\n')
desthpp.write('// Author: Joao Fortuna                                                     *\n')
desthpp.write('//***************************************************************************\n')
desthpp.write('// $Id:: piccolo_messages.py 12867 2013-02-06 03:03:27Z robot             $:*\n')
desthpp.write('//***************************************************************************\n')
desthpp.write('// Automatically generated do not edit.                                     *\n')
desthpp.write('//***************************************************************************\n\n')

destcpp.write('//***************************************************************************\n')
destcpp.write('// Copyright (C) 2007-2013 Laboratório de Sistemas e Tecnologia Subaquática *\n')
destcpp.write('// Departamento de Engenharia Electrotécnica e de Computadores              *\n')
destcpp.write('// Rua Dr. Roberto Frias, 4200-465 Porto, Portugal                          *\n')
destcpp.write('//***************************************************************************\n')
destcpp.write('// Author: Joao Fortuna                                                     *\n')
destcpp.write('//***************************************************************************\n')
destcpp.write('// $Id:: piccolo_messages.py 12867 2013-02-06 03:03:27Z robot             $:*\n')
destcpp.write('//***************************************************************************\n')
destcpp.write('// Automatically generated do not edit.                                     *\n')
destcpp.write('//***************************************************************************\n\n')

desthpp.write('#ifndef PICCOLO_DEFINITIONS_HPP_INCLUDED_\n')
desthpp.write('#define PICCOLO_DEFINITIONS_HPP_INCLUDED_\n\n')

desthpp.write('#include "PiccoloMessage.hpp"\n\n')
desthpp.write('namespace Piccolo\n{\n')

destcpp.write('#include "PiccoloDefinitions.hpp"\n')
destcpp.write('namespace Piccolo\n{\n')

for thr in root.findall("message"):
    has_flags = 0
    not_first_flag = 0
    has_enums = 0
    not_first_enum = 0

    if thr.get('id').startswith('POLLING'):
        message_id = polling_id + int(filter(str.isdigit, thr.get('id')))
    if thr.get('id').startswith('DGPS'):
        message_id = dgps_id + int(filter(str.isdigit, thr.get('id')))
    if thr.get('id').startswith('PILOT'):
        message_id = pilot_id + int(filter(str.isdigit, thr.get('id')))
    if thr.get('id').startswith('AP'):
        message_id = ap_id + int(filter(str.isdigit, thr.get('id')))
    if thr.get('id').startswith('GS'):
        message_id = gs_id + int(filter(str.isdigit, thr.get('id')))
    if thr.get('id').startswith('GIMBAL'):
        message_id = gimbal_id + int(filter(str.isdigit, thr.get('id')))

############################################################################
#                                   HPP                                    #
############################################################################

    desthpp.write('  class %s : public PiccoloMessage\n  {\n' % thr.get('abbrev'))
    desthpp.write('  public:\n')

    for f in thr.findall('field'):
        if (str(f.get('unit')) == 'Bitmask'):
            if (has_flags == 0):
                has_flags = 1;
                desthpp.write('    enum FlagsBits\n')
                desthpp.write('    {\n')
            for b in f.findall('bitmask'):
                if (str(b.get('abbrev')) != 'Reserved'):
                    if not_first_flag:
                        desthpp.write(',\n')
                    desthpp.write('      //! %s\n' % b.get('name'))
                    desthpp.write('      %s_%s = %s' % (f.get('prefix') , b.get('abbrev'), b.get('id')))
                    not_first_flag = 1;
    if has_flags:
        desthpp.write('\n    };\n\n')

    for f in thr.findall('field'):
        if (str(f.get('unit')) == 'Enumerated'):
            if (has_enums == 0):
                has_enums = 1;
                desthpp.write('    enum Enum%s\n' % thr.get('abbrev'))
                desthpp.write('    {\n')
            for e in f.findall('enum'):
                if (str(e.get('abbrev')) != 'Reserved'):
                    if not_first_enum:
                        desthpp.write(',\n')
                    desthpp.write('      //! %s\n' % e.get('name'))
                    desthpp.write('      %s_%s = %s' % (f.get('prefix') , e.get('abbrev'), e.get('id')))
                    not_first_enum = 1;
    if has_enums:
        desthpp.write('\n    };\n\n')

    for f in thr.findall('field'):
        desthpp.write('    //!%(name)s' % f.attrib)
        if (str(f.get('unit')) != 'None'):
            desthpp.write(', unit: %s' % f.get('unit'))
        desthpp.write('\n')
        desthpp.write('    %(type)s %(abbrev)s;\n' % f.attrib)

    desthpp.write('\n')
    desthpp.write('    %s(void);\n\n' % thr.get('abbrev'))
    desthpp.write('    void\n')
    desthpp.write('    clear(void);\n\n')
    desthpp.write('    static uint16_t\n')
    desthpp.write('    getIdStatic(void)\n')
    desthpp.write('    {\n')
    desthpp.write('      return %d;\n' % message_id)
    desthpp.write('    }\n\n')
    desthpp.write('    const char*\n')
    desthpp.write('    getName(void) const\n')
    desthpp.write('    {\n')
    desthpp.write('      return "%s";\n' % thr.get('abbrev'))
    desthpp.write('    }\n\n')
    desthpp.write('    uint16_t\n')
    desthpp.write('    getId(void) const\n')
    desthpp.write('    {\n')
    desthpp.write('      return %s::getIdStatic();\n' % thr.get('abbrev'))
    desthpp.write('    }\n\n')
    desthpp.write('    uint8_t*\n')
    desthpp.write('    serializeFields(uint8_t* bfr__) const;\n\n')
    desthpp.write('    void\n')
    desthpp.write('    deserializeFields(const uint8_t* bfr__);\n\n')
    desthpp.write('  };\n\n')

############################################################################
#                                   CPP                                    #
############################################################################

    destcpp.write('    ' + thr.get('abbrev') + '::' + thr.get('abbrev') + '(void)\n')
    destcpp.write('    {\n')
    destcpp.write('      m_id = %d;\n' % message_id)
    destcpp.write('      clear();\n')
    destcpp.write('    }\n\n')
    destcpp.write('    void\n')
    destcpp.write('    ' + thr.get('abbrev') + '::clear(void)\n')
    destcpp.write('    {\n')
    for f in thr.findall('field'):
        destcpp.write('      %(abbrev)s = 0;\n' % f.attrib)
    destcpp.write('    }\n\n')

destcpp.write('}')

desthpp.write('}\n\n')
desthpp.write('#endif\n\n')

