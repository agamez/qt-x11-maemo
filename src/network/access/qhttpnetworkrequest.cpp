/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the QtNetwork module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qhttpnetworkrequest_p.h"
#include "private/qnoncontiguousbytedevice_p.h"

QT_BEGIN_NAMESPACE

QHttpNetworkRequestPrivate::QHttpNetworkRequestPrivate(QHttpNetworkRequest::Operation op,
        QHttpNetworkRequest::Priority pri, const QUrl &newUrl)
    : QHttpNetworkHeaderPrivate(newUrl), operation(op), priority(pri), uploadByteDevice(0),
      autoDecompress(false)
{
}

QHttpNetworkRequestPrivate::QHttpNetworkRequestPrivate(const QHttpNetworkRequestPrivate &other)
    : QHttpNetworkHeaderPrivate(other)
{
    operation = other.operation;
    priority = other.priority;
    uploadByteDevice = other.uploadByteDevice;
    autoDecompress = other.autoDecompress;
}

QHttpNetworkRequestPrivate::~QHttpNetworkRequestPrivate()
{
}

bool QHttpNetworkRequestPrivate::operator==(const QHttpNetworkRequestPrivate &other) const
{
    return QHttpNetworkHeaderPrivate::operator==(other)
        && (operation == other.operation)
        && (uploadByteDevice == other.uploadByteDevice);
}

QByteArray QHttpNetworkRequestPrivate::methodName() const
{
    QByteArray ba;
    switch (operation) {
    case QHttpNetworkRequest::Options:
        ba += "OPTIONS";
        break;
    case QHttpNetworkRequest::Get:
        ba += "GET";
        break;
    case QHttpNetworkRequest::Head:
        ba += "HEAD";
        break;
    case QHttpNetworkRequest::Post:
        ba += "POST";
        break;
    case QHttpNetworkRequest::Put:
        ba += "PUT";
        break;
    case QHttpNetworkRequest::Delete:
        ba += "DELETE";
        break;
    case QHttpNetworkRequest::Trace:
        ba += "TRACE";
        break;
    case QHttpNetworkRequest::Connect:
        ba += "CONNECT";
        break;
    default:
        break;
    }
    return ba;
}

QByteArray QHttpNetworkRequestPrivate::uri(bool throughProxy) const
{
    QUrl::FormattingOptions format(QUrl::RemoveFragment);

    // for POST, query data is send as content
    if (operation == QHttpNetworkRequest::Post && !uploadByteDevice)
        format |= QUrl::RemoveQuery;
    // for requests through proxy, the Request-URI contains full url
    if (throughProxy)
        format |= QUrl::RemoveUserInfo;
    else
        format |= QUrl::RemoveScheme | QUrl::RemoveAuthority;
    QByteArray uri = url.toEncoded(format);
    if (uri.isEmpty() || (throughProxy && url.path().isEmpty()))
        uri += '/';
    return uri;
}

QByteArray QHttpNetworkRequestPrivate::header(const QHttpNetworkRequest &request, bool throughProxy)
{
    QByteArray ba = request.d->methodName();
    QByteArray uri = request.d->uri(throughProxy);
    ba += " " + uri;

    QString majorVersion = QString::number(request.majorVersion());
    QString minorVersion = QString::number(request.minorVersion());
    ba += " HTTP/" + majorVersion.toLatin1() + "." + minorVersion.toLatin1() + "\r\n";

    QList<QPair<QByteArray, QByteArray> > fields = request.header();
    QList<QPair<QByteArray, QByteArray> >::const_iterator it = fields.constBegin();
    for (; it != fields.constEnd(); ++it)
        ba += it->first + ": " + it->second + "\r\n";
    if (request.d->operation == QHttpNetworkRequest::Post) {
        // add content type, if not set in the request
        if (request.headerField("content-type").isEmpty())
            ba += "Content-Type: application/x-www-form-urlencoded\r\n";
        if (!request.d->uploadByteDevice && request.d->url.hasQuery()) {
            QByteArray query = request.d->url.encodedQuery();
            ba += "Content-Length: "+ QByteArray::number(query.size()) + "\r\n";
            ba += "\r\n";
            ba += query;
        } else {
            ba += "\r\n";
        }
    } else {
        ba += "\r\n";
    }
     return ba;
}


// QHttpNetworkRequest

QHttpNetworkRequest::QHttpNetworkRequest(const QUrl &url, Operation operation, Priority priority)
    : d(new QHttpNetworkRequestPrivate(operation, priority, url))
{
}

QHttpNetworkRequest::QHttpNetworkRequest(const QHttpNetworkRequest &other)
    : QHttpNetworkHeader(other), d(other.d)
{
}

QHttpNetworkRequest::~QHttpNetworkRequest()
{
}

QUrl QHttpNetworkRequest::url() const
{
    return d->url;
}
void QHttpNetworkRequest::setUrl(const QUrl &url)
{
    d->url = url;
}

qint64 QHttpNetworkRequest::contentLength() const
{
    return d->contentLength();
}

void QHttpNetworkRequest::setContentLength(qint64 length)
{
    d->setContentLength(length);
}

QList<QPair<QByteArray, QByteArray> > QHttpNetworkRequest::header() const
{
    return d->fields;
}

QByteArray QHttpNetworkRequest::headerField(const QByteArray &name, const QByteArray &defaultValue) const
{
    return d->headerField(name, defaultValue);
}

void QHttpNetworkRequest::setHeaderField(const QByteArray &name, const QByteArray &data)
{
    d->setHeaderField(name, data);
}

QHttpNetworkRequest &QHttpNetworkRequest::operator=(const QHttpNetworkRequest &other)
{
    d = other.d;
    return *this;
}

bool QHttpNetworkRequest::operator==(const QHttpNetworkRequest &other) const
{
    return d->operator==(*other.d);
}

QHttpNetworkRequest::Operation QHttpNetworkRequest::operation() const
{
    return d->operation;
}

void QHttpNetworkRequest::setOperation(Operation operation)
{
    d->operation = operation;
}

QHttpNetworkRequest::Priority QHttpNetworkRequest::priority() const
{
    return d->priority;
}

void QHttpNetworkRequest::setPriority(Priority priority)
{
    d->priority = priority;
}

void QHttpNetworkRequest::setUploadByteDevice(QNonContiguousByteDevice *bd)
{
    d->uploadByteDevice = bd;
}

QNonContiguousByteDevice* QHttpNetworkRequest::uploadByteDevice() const
{
    return d->uploadByteDevice;
}

int QHttpNetworkRequest::majorVersion() const
{
    return 1;
}

int QHttpNetworkRequest::minorVersion() const
{
    return 1;
}


QT_END_NAMESPACE
