#include "Widget.h"
#include "ui_Widget.h"

#include "SearchHighLight.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // Create and initialize search highlighting
    m_searchHighLight = new SearchHighLight(ui->textEdit->document());

    // We connect the signal of the button to the slots for calling the search.
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::onSearchText);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onSearchText()
{
    // We load the text for search in syntax highlighting
    m_searchHighLight->searchText(ui->lineEdit->text());
}
