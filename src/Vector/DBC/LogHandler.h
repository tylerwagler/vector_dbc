/*
 * Copyright (C) 2013-2019 Tobias Lorenz.
 * Contact: tobias.lorenz@gmx.net
 *
 * This file is part of Tobias Lorenz's Toolkit.
 *
 * Commercial License Usage
 * Licensees holding valid commercial licenses may use this file in
 * accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Tobias Lorenz.
 *
 * GNU General Public License 3.0 Usage
 * Alternatively, this file may be used under the terms of the GNU
 * General Public License version 3.0 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.  Please review the following information to
 * ensure the GNU General Public License version 3.0 requirements will be
 * met: http://www.gnu.org/copyleft/gpl.html.
 */

#pragma once

#include <functional>
#include <string>

#include <Vector/DBC/vector_dbc_export.h>

namespace Vector {
namespace DBC {

/*
 * Pluggable warning sink for the DBC parser.
 *
 * The STW/openSYDE patches emit warnings while tolerating malformed DBC files
 * (e.g. int-as-double conversions, parse errors). Upstream the parser called
 * directly into opensyde_core's C_OscLoggingHandler, which coupled this library
 * to opensyde_core. To keep the library standalone, warnings are routed through
 * this hook instead. The default sink writes to std::cerr; consumers (such as
 * openSYDE) can install a handler that forwards into their own logging.
 */
using LogHandler = std::function<void(const std::string & source, const std::string & message)>;

/* Install a warning handler. Pass an empty std::function to restore the default (stderr). */
VECTOR_DBC_EXPORT void SetLogHandler(const LogHandler & handler);

/* Emit a warning through the installed handler (or the stderr default). */
VECTOR_DBC_EXPORT void LogWarning(const std::string & source, const std::string & message);

}
}
