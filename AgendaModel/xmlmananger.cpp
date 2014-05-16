#include "xmlmananger.h"
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <qdebug.h>
#include <iostream>
XMLMananger::XMLMananger()
{
}

QString XMLMananger::BuildRequestMaterial(model::RequestMaterials request)
{
    QString output;
    QXmlStreamWriter stream(&output);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("root");
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
    stream.writeEndElement();
    stream.writeEndDocument();
    return output;
}

model::RequestMaterials XMLMananger::ParseRequestMaterial(QString source)
{
    model::RequestMaterials rm;
    model::Material m;
    model::Provider p;
    QXmlStreamReader xs(source);
    while (!xs.atEnd()) {
        if (xs.readNextStartElement())
        {
            if(xs.name() =="id")
                rm.setId(xs.readElementText().toInt());
            if(xs.name() == "material_id")
                m.setId(xs.readElementText().toInt());
            if(xs.name() == "material_name")
                m.setName(xs.readElementText());
            if(xs.name()=="material_prince")
                m.setPrince(xs.readElementText().toDouble());
            if(xs.name() == "material_unit")
                m.setUnity(xs.readElementText());
            if(xs.name() == "date")
                rm.setDate(QDate::fromString(xs.readElementText(),"dd/MM/yyyy"));
            if(xs.name() == "qtd")
                rm.setQtd(xs.readElementText().toInt());
            if(xs.name() == "provider_id")
                p.setId(xs.readElementText().toInt());
            if(xs.name() == "provider_name")
                p.setName(xs.readElementText());
            if(xs.name() == "provider_street")
                p.setStreet(xs.readElementText());
            if(xs.name() == "provider_number")
                p.setNumber(xs.readElementText().toInt());
            if(xs.name() == "provider_phonenumber")
                p.setPhoneNumber(xs.readElementText());
        }
    }
    rm.setMaterial(m);
    rm.setProvider(p);
    return rm;

}
