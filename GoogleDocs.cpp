#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// abstraction for document elements
class DocumentEditor
{
public:
    virtual string render() = 0;
};

class Textelement : public DocumentEditor
{
private:
    string text;

public:
    Textelement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

// overriding for image  elements
class imageelements : public DocumentEditor
{
private:
    string imagepath;

public:
    imageelements(string imagepath)
    {
        this->imagepath = imagepath;
    }

    string render() override
    {
        return "[image:" + imagepath + "}";
    }
};

//  newline represents a line break in the document
class newline : public DocumentEditor
{
public:
    string render() override
    {
        return "\n";
    }
};

// tabspace represents a tab space in the document
class tabspace : public DocumentEditor
{
public:
    string render() override
    {
        return "\t";
    }
};

// document class responsible for holding a collection of elements
class document
{
private:
    vector<DocumentEditor *> elements;

public:
    void addelement(DocumentEditor *element)
    {
        elements.push_back(element);
    }

    string render()
    {
        string result;
        for (auto element : elements)
        {
            result += element->render();
        }
        return result;
    }
};
// persistance instance
class persistance
{
private:
    virtual void save(string data) = 0;
};

class filestorage : public persistance
{
public:
    void save(string data) override
    {
        ofstream file("document.txt");
        if (file)
        {
            file << data;
            file.close();
            cout << "data saved to file" << endl;
        }
        else
        {
            cout << "error saving data to file" << endl;
        }
    }
};


class dbstorage : public persistance{

    public: 
    void save(string data) override{
        // save to db 
    }

};

class documenteditor{
    private: 
    document * doc;
    persistance * pers;
    string renderdocument;

    public:
    documenteditor(document * doc, persistance * pers){
        this->doc = doc;
        this->pers = pers;
    }

    void addtext(string text){
        doc->addelement(new Textelement(text));
    }

    void addimage(string imagepath){
        doc->addelement(new imageelements(imagepath));
    }

    void addnewline(){
        doc->addelement(new newline());
    }
    void addtabspace(){
        doc->addelement(new tabspace());
    }   
    string renderdocument(){
        if(renderdocument.empty()){
            renderdocument = doc->render();
        }
        return renderdocument;
    }

    void savedocument(){
        pers->save(renderdocument);
    }
};


