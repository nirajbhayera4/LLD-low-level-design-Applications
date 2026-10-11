
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Abstraction for document elements
class DocumentEditor {
public:
    virtual string render() = 0;
    virtual ~DocumentEditor() = default;
};

// Text element
class Textelement : public DocumentEditor {
private:
    string text;

public:
    Textelement(string text) {
        this->text = text;
    }

    string render() override {
        return text;
    }
};

// Image element
class imageelements : public DocumentEditor {
private:
    string imagepath;

public:
    imageelements(string imagepath) {
        this->imagepath = imagepath;
    }

    string render() override {
        return "[image:" + imagepath + "]";
    }
};

// Newline element
class newline : public DocumentEditor {
public:
    string render() override {
        return "\n";
    }
};

// Tab space element
class tabspace : public DocumentEditor {
public:
    string render() override {
        return "\t";
    }
};

// Document class
class document {
private:
    vector<DocumentEditor*> elements;

public:
    void addelement(DocumentEditor* element) {
        elements.push_back(element);
    }

    string render() {
        string result;

        for (auto element : elements) {
            result += element->render();
        }

        return result;
    }

    ~document() {
        for (auto element : elements) {
            delete element;
        }
    }
};

// Persistence abstraction
class persistance {
public:
    virtual void save(string data) = 0;
    virtual ~persistance() = default;
};

// File storage
class filestorage : public persistance {
public:
    void save(string data) override {
        ofstream file("document.txt");

        if (file.is_open()) {
            file << data;
            file.close();
            cout << "Data saved to file \n" << endl;
        } else {
            cout << "Error saving data to file \n" << endl;
        }
    }
};

// Database storage
class dbstorage : public persistance {
public:
    void save(string data) override {
        // Save to database
        cout << "Database storage selected \n" << endl;
    }
};

// Document editor
class documenteditor {
private:
    document* doc;
    persistance* pers;
    string renderedData;

public:
    documenteditor(document* doc, persistance* pers) {
        this->doc = doc;
        this->pers = pers;
    }

    void addtext(string text) {
        doc->addelement(new Textelement(text));
        renderedData.clear();
    }

    void addimage(string imagepath) {
        doc->addelement(new imageelements(imagepath));
        renderedData.clear();
    }

    void addnewline() {
        doc->addelement(new newline());
        renderedData.clear();
    }

    void addtabspace() {
        doc->addelement(new tabspace());
        renderedData.clear();
    }

    string renderdocument() {
        if (renderedData.empty()) {
            renderedData = doc->render();
        }

        return renderedData;
    }

    void savedocument() {
        pers->save(renderdocument());
    }
};

int main() {
    document* doc = new document();
    persistance* pers = new filestorage();

    documenteditor editor(doc, pers);

    editor.addtext("Hello World!");
    editor.addimage("image.jpg");
    editor.addnewline();
    editor.addtabspace();
    editor.addtext("Google Docs");

    cout << editor.renderdocument() << endl;

    editor.savedocument();

    delete doc;
    delete pers;

    return 0;
}
