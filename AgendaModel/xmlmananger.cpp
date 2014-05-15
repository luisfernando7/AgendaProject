#include "xmlmananger.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

XMLMananger::XMLMananger()
{
}

QString XMLMananger::BuildRequestMaterial(model::RequestMaterials request)
{
    QString output;
    QXmlStreamWriter stream(&output);
    stream.setAutoFormatting(false);
    stream.writeStartDocument();

    stream.writeStartElement("request_materials");//Primeiro Elemento
    stream.writeTextElement("id", QString::number(request.id()));
    stream.writeStartElement("material");//Segundo elemento
    stream.writeTextElement("material_id",QString::number(request.material().getId()));
    stream.writeTextElement("material_name",request.material().name());
    stream.writeTextElement("material_prince",QString::number(request.material().prince()));
    stream.writeTextElement("material_unit",request.material().unity());
    stream.writeEndElement();//Segundo elemento
    stream.writeTextElement("date",request.date().toString("dd/MM/yyyy"));
    stream.writeTextElement("qtd",QString::number(request.qtd()));
    stream.writeStartElement("provider");//Terceiro elemento
    stream.writeTextElement("provider_id",QString::number(request.provider().getId()));
    stream.writeTextElement("provider_name",request.provider().name());
    stream.writeTextElement("provider_street",request.provider().street());
    stream.writeTextElement("provider_number",QString::number(request.provider().number()));
    stream.writeTextElement("provider_phonenumber",request.provider().phoneNumber());
    stream.writeEndElement();//Terceiro elemento
    stream.writeEndElement();//Primeiro Elemento
    stream.writeEndDocument();
     return output;
}

model::RequestMaterials XMLMananger::ParseRequestMaterial(QString source)
{
    model::RequestMaterials rm;
    QXmlStreamReader xml(source);
    while (!m_streamReader.atEnd()) {
            QXmlStreamReader::TokenType tt = m_streamReader.readNext();
            switch (tt) {
                case QXmlStreamReader::StartElement: {
                    QString name = m_streamReader.name().toString();
                    QStandardItem* item = new QStandardItem(name);
                    item->setData(m_streamReader.lineNumber(),
                                  LineStartRole);             /* Custom data() */
                    QXmlStreamAttributes attrs = m_streamReader.attributes();
                    QStringList sl;
                    sl << tr("Line# %1").arg(m_streamReader.lineNumber());
                    foreach (QXmlStreamAttribute attr, attrs) {
                        QString line = QString("%1='%2'").arg(attr.name().toString())
                                        .arg(attr.value().toString());
                        sl.append(line);
                    }
                    item->setToolTip(sl.join("\n"));
                    if (m_currentItem == 0)
                       setItem(0, 0, item);                   /* Set root item in model. */
                    else
                       m_currentItem->appendRow(item);        /* Add as a child to the current item. */
                    m_currentItem = item;
                    break; }
                case QXmlStreamReader::Characters: {
                    QString tt = m_currentItem->toolTip();
                    tt.append("\n");
                    tt.append(m_streamReader.text().toString());
                    m_currentItem->setToolTip(tt);
                    break; }
                case QXmlStreamReader::EndElement:
                    m_currentItem->setData(m_streamReader.lineNumber(), LineEndRole);
                    m_currentItem = m_currentItem->parent();  /* Go up the tree. */
                    break;
                case QXmlStreamReader::EndDocument:
                default:
                    break;
            }
        }
    bool error = xml.hasError();
    QStringRef text = xml.text();
    QXmlStreamAttributes attributes = xml.attributes();
    QString id = attributes.value("request_materials").toString();
    return rm;

}
