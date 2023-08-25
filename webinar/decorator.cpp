#include <string>
#include <iostream>

class Text {
public:
    Text() 
    {
        std::cout << "Text constructor\n";
    };
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {
        std::cout << "DecoratedText constructor\n";
    }
    Text* text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {
        std::cout << "ItalicText constructor\n";
    }
    void render(const std::string& data)  const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {
        std::cout << "BoldText constructor\n";
    }
    void render(const std::string& data) const {

        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

int main3() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    return 0;
}