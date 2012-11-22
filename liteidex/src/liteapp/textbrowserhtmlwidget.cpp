/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011 LiteIDE Team. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: textbrowserhtmlwidget.cpp
// Creator: visualfc <visualfc@gmail.com>
// date: 2012-11-22
// $Id: textbrowserhtmlwidget.cpp,v 1.0 2012-11-22 visualfc Exp $

#include "textbrowserhtmlwidget.h"
#include <QTextBrowser>
#include <QScrollBar>
//lite_memory_check_begin
#if defined(WIN32) && defined(_MSC_VER) &&  defined(_DEBUG)
     #define _CRTDBG_MAP_ALLOC
     #include <stdlib.h>
     #include <crtdbg.h>
     #define DEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
     #define new DEBUG_NEW
#endif
//lite_memory_check_end

TextBrowserHtmlWidget::TextBrowserHtmlWidget(QObject *parent) :
    IHtmlWidget(parent)
{
    m_widget = new QTextBrowser;
    m_widget->setOpenLinks(false);
    m_widget->setOpenExternalLinks(false);
    connect(m_widget,SIGNAL(anchorClicked(QUrl)),this,SIGNAL(linkClicked(QUrl)));
    connect(m_widget,SIGNAL(highlighted(QUrl)),this,SIGNAL(linkHovered(QUrl)));
}

QWidget *TextBrowserHtmlWidget::widget() const
{
    return m_widget;
}

QString TextBrowserHtmlWidget::className() const
{
    return QLatin1String("QTextBrowser");
}

void TextBrowserHtmlWidget::setSerachPaths(const QStringList &paths)
{
    m_widget->setSearchPaths(paths);
}

void TextBrowserHtmlWidget::setHtml(const QString &html, const QUrl &url)
{
    m_widget->setHtml(html);
}

void TextBrowserHtmlWidget::setMarkdown(const QByteArray &data, const QUrl &url)
{
}

void TextBrowserHtmlWidget::setText(const QString &text, const QUrl &url)
{
    m_widget->setText(text);
}

void TextBrowserHtmlWidget::clear()
{
    m_widget->clear();
}

void TextBrowserHtmlWidget::scroolToAnchor(const QString &anchor)
{
    m_widget->scrollToAnchor(anchor);
}

QPoint TextBrowserHtmlWidget::scrollPos() const
{
    return QPoint(m_widget->horizontalScrollBar()->value(),m_widget->verticalScrollBar()->value());
}

void TextBrowserHtmlWidget::setScrollPos(const QPoint &pos)
{
    m_widget->horizontalScrollBar()->setValue(pos.x());
    m_widget->verticalScrollBar()->setValue(pos.y());
}

QString TextBrowserHtmlWidget::selectedText() const
{
    return m_widget->textCursor().selectedText();
}

bool TextBrowserHtmlWidget::findText(const QString &exp, QTextDocument::FindFlags options)
{
    return m_widget->find(exp,options);
}

TextBrowserHtmlWidgetFactory::TextBrowserHtmlWidgetFactory(QObject *parent)
    : IHtmlWidgetFactory(parent)
{
}

QString TextBrowserHtmlWidgetFactory::className() const
{
    return "QTextBrowser";
}

IHtmlWidget *TextBrowserHtmlWidgetFactory::create(QObject *parent)
{
    return new TextBrowserHtmlWidget(parent);
}