/**************************************************************************
**
** This file is part of Installer Framework
**
** Copyright (c) 2010-2012 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef ERRORS_H
#define ERRORS_H

#include <QtCore/QDebug>
#include <QtCore/QString>

#include <stdexcept>

namespace QInstaller {

class Error : public std::runtime_error
{
public:
    explicit Error(const QString &message)
        : std::runtime_error(message.toStdString())
        , m_message (message) { qDebug() << "Error-Exception:" << message; }
    virtual ~Error() throw() {}

    QString message() const { return m_message; }

private:
    QString m_message;
};

}

#endif // ERRORS_H
