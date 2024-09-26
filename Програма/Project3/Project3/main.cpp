// Include necessary libraries
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <locale>
#include <sstream>
#define NOMINMAX
#include <Windows.h>
#include <memory> 

using namespace std;

std::map<std::string, std::string> translations;
std::map<std::string, std::string> loadLanguageFile(const std::string& filename)
{
    std::map<std::string, std::string> translations;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string id, trans;
        if (std::getline(std::getline(iss, id, '='), trans))
        {
            translations[id] = trans;
        }
    }
    return translations;
}
class TreeType {
public:
    TreeType() = default;
    TreeType(int objectId, string type, string colour, string texture, double height, double width)
        : objectId_(objectId), type_(std::move(type)), colour_(std::move(colour)), texture_(std::move(texture)), height_(height), width_(width) {}

    int getObjectId() const { return objectId_; }
    const string getTypeId() const { return type_; }
    const string& getColour() const { return colour_; }
    const string& getTexture() const { return texture_; }
    double getHeight() const { return height_; }
    double getWidth() const { return width_; }
    void addElement(TreeType* element) {
        if (element != nullptr) {
            children_.push_back(element);
        }
    }

private:
    int objectId_;
    string type_, colour_, texture_;
    double height_, width_;
    std::vector<TreeType*> children_;
};
class Tree : public TreeType
{
private:
    int objectId;
    string type;
    string colour;
    string texture;
    double height;
    double width;

public:
    // Constructors
    Tree() = default;
    Tree(int objectId, string type, string colour, string texture, double height, double width)
        : TreeType(objectId, type, std::move(colour), std::move(texture), height, width) {}
    // Getters
    int getObjectId() { return objectId; }
    string getTypeId() { return type; }
    string getColour() { return colour; }
    string getTexture() { return texture; }
    double getHeight() { return height; }
    double getWidth() { return width; }

    // Setters
    void setObjectId(int objectId) { this->objectId = objectId; }
    void setTypeId(string type) { this->type = type; }
    void setColour(string colour) { this->colour = colour; }
    void setTexture(string texture) { this->texture = texture; }
    void setHeight(double height) { this->height = height; }
    void setWidth(double width) { this->width = width; }
};
class TreeFactory : public TreeType
{
public:
    TreeFactory() = default;


    static int nextId;

    static TreeType* createTree(const string& Type, const string& Colour, const string& Texture, int Height, int Width)
    {
        TreeType* tree = new TreeType(nextId, Type, Colour, Texture, static_cast<double>(Height), static_cast<double>(Width));
        trees[nextId] = tree;
        nextId++;
        return tree;
    }
    static void saveToFile(const string& filename)
    {
        ofstream file(filename);
        if (!file)
        {
            cout << translations["Cannot_openfile.\n"];
            return;
        }

        // Make sure trees is defined and accessible
        for (auto it = trees.begin(); it != trees.end(); ++it)
        {
            file << it->second->getObjectId() << " "
                << it->second->getTypeId() << " "
                << it->second->getColour() << " "
                << it->second->getTexture() << " "
                << it->second->getHeight() << " "
                << it->second->getWidth() << "\n";
        }

        file.close();
    }

    // Static map to store tree objects
    static map<int, TreeType*> trees;

    // Method to create a new tree object
    static TreeType* createTree(int Object_id, string Type, const string& Colour, const string& Texture, int Height, int Width)
    {
        TreeType* tree = new TreeType(Object_id, Type, Colour, Texture, Height, Width);
        trees[Object_id] = tree;
        return tree;
    }

    // Method to input tree data from the user
// Method to input tree data from the user
    static void inputTree(std::map<int, TreeType*>& tree, std::map<std::string, std::string>& translations) {
        int Height, Width;
        string Type, Colour, Texture;
        int Object_id = nextId; // Автоматическое присвоение ID

        // Очистка потока ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int colourOption;
        bool validColour = false; // Добавляем переменную для проверки валидности ввода
        do {
            cout << translations["select_colour"] << "\n";
            cout << "1. " << translations["red"] << "  ";
            cout << "2. " << translations["green"] << "  ";
            cout << "3. " << translations["blue"] << "  ";
            cout << "4. " << translations["black"] << "  ";
            cout << "5. " << translations["white"] << "  ";
            cout << "6. " << translations["gray"] << "  ";
            cout << "7. " << translations["purple"] << "  ";
            cout << "8. " << translations["orange"] << "  ";
            cout << "9. " << translations["pink"] << "  ";
            cout << "10. " << translations["brown"] << "\n";

            if (cin >> colourOption && colourOption >= 1 && colourOption <= 10) {
                validColour = true;
            }
            else {
                cout << "Invalid input. Please enter a number between 1 and 10.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (!validColour);

        // Проверка и установка выбранного цвета после валидации
        switch (colourOption) {
        case 1: Colour = translations["red"]; break;
        case 2: Colour = translations["green"]; break;
        case 3: Colour = translations["blue"]; break;
        case 4: Colour = translations["black"]; break;
        case 5: Colour = translations["white"]; break;
        case 6: Colour = translations["gray"]; break;
        case 7: Colour = translations["purple"]; break;
        case 8: Colour = translations["orange"]; break;
        case 9: Colour = translations["pink"]; break;
        case 10: Colour = translations["brown"]; break;
        }

        // Вывод опций текстуры горизонтально
        int textureOption;
        bool validTexture = false;
        while (!validTexture) {
            cout << translations["select_texture"] << "\n";
            cout << "1. " << translations["smooth"] << "  ";
            cout << "2. " << translations["rough"] << "  ";
            cout << "3. " << translations["matte"] << "  ";
            cout << "4. " << translations["glossy"] << "  ";
            cout << "5. " << translations["metallic"] << "\n";
            if (cin >> textureOption && textureOption >= 1 && textureOption <= 5) {
                validTexture = true; // Input is within the valid range
            }
            else {
                cout << "Invalid input. Please enter a number between 1 and 5.\n";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            }
        }
        switch (textureOption) {
        case 1: Texture = translations["smooth"]; break;
        case 2: Texture = translations["rough"]; break;
        case 3: Texture = translations["matte"]; break;
        case 4: Texture = translations["glossy"]; break;
        case 5: Texture = translations["metallic"]; break;
        }

        cout << translations["enter_height"] << ": ";
        while (!(cin >> Height)) {
            cout << translations["invalid_input_number"] << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << translations["enter_width"] << ": ";
        while (!(cin >> Width)) {
            cout << translations["invalid_input_number"] << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int TypeOption;
        bool validType = false;
        while (!validType) {
            cout << translations["select_type"] << "\n";
            cout << "1. " << translations["circle"] << "  ";
            cout << "2. " << translations["rectangle"] << "  ";
            cout << "3. " << translations["triangle"] << "\n";
            if (cin >> TypeOption && TypeOption >= 1 && TypeOption <= 3) {
                validType = true;
            }
            else {
                cout << "Invalid input. Please enter a number between 1 and 3.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        switch (TypeOption) {
        case 1: Type = translations["circle"]; break;
        case 2: Type = translations["rectangle"]; break;
        case 3: Type = translations["triangle"]; break;
        }

        // Поиск последнего элемента в контейнере и добавление нового объекта
        auto LastElement = tree.end();
        tree.insert(LastElement, make_pair(Object_id, createTree(Object_id, Type, Colour, Texture, Height, Width)));
    }


    // Function to calculate the width of a string in characters
    static int calculateWidth(const std::string& str)
    {
        return static_cast<int>(str.length());
    }

    // Function to print all trees with adjusted widths
    static void printAllTrees(std::map<std::string, std::string> translations)
    {
        // Calculate width for each header
        int objectIdWidth = calculateWidth(translations["object_id"]);
        int typeIdWidth = calculateWidth(translations["type_id"]);
        int colourWidth = calculateWidth(translations["colour"]);
        int textureWidth = calculateWidth(translations["texture"]);
        int heightWidth = calculateWidth(translations["height"]);
        int widthWidth = calculateWidth(translations["width"]);

        // Calculate maximum width for each column
        for (auto it = trees.begin(); it != trees.end(); ++it)
        {
            objectIdWidth = max(objectIdWidth, calculateWidth(std::to_string(it->second->getObjectId())));
            heightWidth = max(heightWidth, calculateWidth(std::to_string(it->second->getHeight())));
            widthWidth = max(widthWidth, calculateWidth(std::to_string(it->second->getWidth())));
        }

        // Output the header with adjusted widths
        cout << left << setw(objectIdWidth + 2) << translations["object_id"]
            << "|" << setw(typeIdWidth + 2) << translations["type_id"]
            << "|" << setw(colourWidth + 2) << translations["colour"]
            << "|" << setw(textureWidth + 2) << translations["texture"]
            << "|" << setw(heightWidth + 2) << translations["height"]
            << "|" << setw(widthWidth + 2) << translations["width"] << "\n";
        cout << string(objectIdWidth + typeIdWidth + colourWidth + textureWidth + heightWidth + widthWidth + 13, '-') << "\n";

        // Output the tree data with adjusted widths
        for (auto it = trees.begin(); it != trees.end(); ++it)
        {
            cout << setw(objectIdWidth + 2) << it->second->getObjectId()
                << "|" << setw(typeIdWidth + 2) << it->second->getTypeId()
                << "|" << setw(colourWidth + 2) << it->second->getColour()
                << "|" << setw(textureWidth + 2) << it->second->getTexture()
                << "|" << setw(heightWidth + 2) << it->second->getHeight()
                << "|" << setw(widthWidth + 2) << it->second->getWidth() << "\n";
        }
    }

    // Method to print tree objects in sorted order
    static void sortTrees(std::vector<TreeType*>& trees, const std::string& sortBy) {
        if (sortBy == "Colour") {
            std::sort(trees.begin(), trees.end(), [](const TreeType* a, const TreeType* b) {
                return a->getColour() < b->getColour();
                });
        }
        else if (sortBy == "Type") {
            std::sort(trees.begin(), trees.end(), [](const TreeType* a, const TreeType* b) {
                return a->getTypeId() < b->getTypeId();
                });
        }
        else if (sortBy == "Texture") {
            std::sort(trees.begin(), trees.end(), [](const TreeType* a, const TreeType* b) {
                return a->getTexture() < b->getTexture();
                });
        }
    }

    // Updated method to print tree objects in sorted order
    static void printSortedTrees(std::map<std::string, std::string> translations) {
        cout << "Select sort option:\n1. Colour\n2. Type\n3. Texture\nEnter choice: ";
        int choice;
        cin >> choice;
        string sortBy;
        switch (choice) {
        case 1: sortBy = "Colour"; break;
        case 2: sortBy = "Type"; break;
        case 3: sortBy = "Texture"; break;
        default: cout << "Invalid choice, sorting by Type by default.\n"; sortBy = "Type";
        }

        // Convert map to vector for sorting
        std::vector<TreeType*> sortedTrees;
        for (auto& it : trees) {
            sortedTrees.push_back(it.second);
        }

        // Sort the trees
        sortTrees(sortedTrees, sortBy);

        // Recalculate widths for sorted output
        int objectIdWidth = calculateWidth(translations["object_id"]);
        int typeIdWidth = calculateWidth(translations["type_id"]);
        int colourWidth = calculateWidth(translations["colour"]);
        int textureWidth = calculateWidth(translations["texture"]);
        int heightWidth = calculateWidth(translations["height"]);
        int widthWidth = calculateWidth(translations["width"]);

        for (auto tree : sortedTrees) {
            objectIdWidth = max(objectIdWidth, calculateWidth(std::to_string(tree->getObjectId())));
            typeIdWidth = max(typeIdWidth, calculateWidth(tree->getTypeId()));
            colourWidth = max(colourWidth, calculateWidth(tree->getColour()));
            textureWidth = max(textureWidth, calculateWidth(tree->getTexture()));
            heightWidth = max(heightWidth, calculateWidth(std::to_string(tree->getHeight())));
            widthWidth = max(widthWidth, calculateWidth(std::to_string(tree->getWidth())));
        }

        // Output the header with adjusted widths
        cout << left << setw(objectIdWidth + 2) << translations["object_id"]
            << "|" << setw(typeIdWidth + 2) << translations["type_id"]
            << "|" << setw(colourWidth + 2) << translations["colour"]
            << "|" << setw(textureWidth + 2) << translations["texture"]
            << "|" << setw(heightWidth + 2) << translations["height"]
            << "|" << setw(widthWidth + 2) << translations["width"] << "\n";
        cout << string(objectIdWidth + typeIdWidth + colourWidth + textureWidth + heightWidth + widthWidth + 13, '-') << "\n";

        // Output sorted tree data
        for (auto tree : sortedTrees) {
            cout << setw(objectIdWidth + 2) << tree->getObjectId()
                << "|" << setw(typeIdWidth + 2) << tree->getTypeId()
                << "|" << setw(colourWidth + 2) << tree->getColour()
                << "|" << setw(textureWidth + 2) << tree->getTexture()
                << "|" << setw(heightWidth + 2) << tree->getHeight()
                << "|" << setw(widthWidth + 2) << tree->getWidth() << "\n";
        }
    }
    // Function to perform secondary sorting based on a preferred attribute value
    void secondarySort(std::vector<TreeType*>& trees, const std::string& attribute, const std::string& preferredValue) {
        std::stable_sort(trees.begin(), trees.end(), [&](const TreeType* a, const TreeType* b) {
            if (attribute == "Colour") {
                if (a->getColour() == preferredValue && b->getColour() != preferredValue)
                    return true;
                return false;
            }
            else if (attribute == "Type") {
                if (a->getTypeId() == preferredValue && b->getTypeId() != preferredValue)
                    return true;
                return false;
            }
            else if (attribute == "Texture") {
                if (a->getTexture() == preferredValue && b->getTexture() != preferredValue)
                    return true;
                return false;
            }
            return false; // Default case
            });
    }
    // Method to read tree data from a file
    static void readFromFile(const string& filename, int langChoice) {
        ifstream file(filename);
        if (!file) {
            cout << translations["file_not_found"] << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            int objectId;
            string type, colour, texture;
            double height, width;
            if (iss >> objectId >> type >> colour >> texture >> height >> width) {
                createTree(objectId, type, colour, texture, height, width);
            }
            else {
                cout << translations["invalid_data_format"] << endl;
            }
        }

        file.close();
        int maxObjectId = 0;
        for (const auto& pair : TreeFactory::trees) {
            maxObjectId = max(maxObjectId, pair.first);
        }

        TreeFactory::nextId = maxObjectId + 1;
    }


    // Method to find a tree object by object ID
    static TreeType* findTree(int Object_id)
    {
        if (trees.find(Object_id) != trees.end())
            return trees[Object_id];
        else
            return nullptr;
    }
};
int TreeFactory::nextId = 1;
map<int, TreeType*> TreeFactory::trees;
int calculateWidth(const std::wstring& str)
{
    return static_cast<int>(str.length());
}
void printTableHeader(std::map<std::string, std::wstring>& translations)
{
    int objectIdWidth = calculateWidth(translations["object_id"]);
    int typeIdWidth = calculateWidth(translations["type"]);
    int colourWidth = calculateWidth(translations["colour"]);
    int textureWidth = calculateWidth(translations["texture"]);
    int heightWidth = calculateWidth(translations["height"]);
    int widthWidth = calculateWidth(translations["width"]);

    // Output the header with adjusted widths
    wcout << left << setw(objectIdWidth + 1) << translations["object_id"] << L"|"
        << setw(typeIdWidth + 1) << translations["type_id"] << L"|"
        << setw(colourWidth + 1) << translations["colour"] << L"|"
        << setw(textureWidth + 1) << translations["texture"] << L"|"
        << setw(heightWidth + 1) << translations["height"] << L"|"
        << setw(widthWidth + 1) << translations["width"] << endl;

    // Output the separator line
    wcout << wstring(objectIdWidth + typeIdWidth + colourWidth + textureWidth + heightWidth + widthWidth + 14, '-') << endl;
}
std::vector<std::string> wrap(const std::string& text, size_t line_length)
{
    std::istringstream words(text);
    std::vector<std::string> lines;
    std::string line;

    while (words)
    {
        std::string word;
        words >> word;

        if (line.length() + word.length() > line_length)
        {
            lines.push_back(line);
            line = word;
        }
        else
        {
            line += (line.empty() ? "" : " ") + word;
        }
    }

    if (!line.empty())
    {
        lines.push_back(line);
    }

    return lines;
}
class Forest :public TreeFactory, public Tree
{
public:
    Forest() : nextObjectId_(1) {}

    TreeType* addTree(const string& type, const string& colour, const string& texture, double height, double width) {
        auto tree = make_unique<TreeType>(TreeFactory::nextId++, type, colour, texture, height, width);
        auto rawPtr = tree.get();
        TreeFactory::trees[TreeFactory::nextId - 1] = rawPtr;
        trees_.push_back(move(tree));
        return rawPtr;
    }


    void printAllTrees() const {
        for (const auto& tree : trees_) {
            cout << "Object ID: " << tree->getObjectId()
                << ", Type : " << tree->getTypeId()
                << ", Colour: " << tree->getColour()
                << ", Texture: " << tree->getTexture()
                << ", Height: " << tree->getHeight()
                << ", Width: " << tree->getWidth() << endl;
        }
    }

private:
    vector<unique_ptr<TreeType>> trees_;
    int nextObjectId_;
};
    

// Main function
int main()
{
    Forest forest;

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int langChoice;
    std::cout << "1. English\n";
    std::cout << "2. Ukrainian\n";
    std::cout << "Enter your choice: ";
    std::cin >> langChoice;

    std::map<std::string, std::string> translations;
    switch (langChoice)
    {
    case 1:
        translations = loadLanguageFile("english.txt");
        break;
    case 2:
        translations = loadLanguageFile("ukrainian.txt");
        break;
    default:
        std::cout << "Invalid choice. Default language applied.\n";
        translations = loadLanguageFile("english.txt");
        break;
    }
    // Before reading the file
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Now you can use the translations map to get the translated strings

    int choice;
    string filename;
    int Object_id;
    TreeType* tree;

    do
    {

        cout << endl;
        cout << "-----------------------------------------------\n";

        std::vector<std::string> lines = wrap(translations["welcome"], 70);
        for (const std::string& line : lines)
        {
            cout << line << "\n";
        }

        cout << "-----------------------------------------------\n"
            << endl;

        cout << translations["read_data"] << "\n";
        cout << translations["add_item"] << "\n";
        cout << translations["display_sorted"] << "\n";
        cout << translations["object_search"] << "\n";
        cout << translations["exit"] << "\n";
        cout << translations["save_changes"] << "\n";
        cout << translations["clear_console"] << "\n";
        cout << translations["enter_choice"] << "\n";
        cin >> choice;

     

        switch (choice)
        {
        case 1:
            cout << translations["enter_file_name"] << ": ";
            cin >> filename;
            TreeFactory::readFromFile(filename, langChoice);
            break;
        case 2:
            TreeFactory::inputTree(TreeFactory::trees, translations);
            break;
        case 3:
            TreeFactory::printSortedTrees(translations);
            break;
        case 4:
            cout << translations["enter_object_id"] << ": ";
            cin >> Object_id;
            tree = TreeFactory::findTree(Object_id);
            if (tree)
            {
                cout << translations["object_found"] << "\n";
                cout << left << setw(15) << translations["object_id"]
                    << "|" << setw(15) << translations["type_id"]
                    << "|" << setw(15) << translations["colour"]
                    << "|" << setw(15) << translations["texture"]
                    << "|" << setw(15) << translations["height"]
                    << "|" << setw(15) << translations["width"] << "\n";
                cout << "-----------------------------------------------------------------------------------------------------------------"
                    << "\n";
                cout << setw(15) << tree->getObjectId() << "|" << setw(15) << tree->getTypeId() << "|" << setw(15) << tree->getColour() << "|" << setw(15) << tree->getTexture() << "|" << setw(15) << tree->getHeight() << "|" << setw(15) << tree->getWidth() << "\n";
            }
            else
                std::cout << translations["object_not_found"] << "\n";
            break;
        case 5:
            exit(0);

        case 6:
            TreeFactory::saveToFile(filename);
            break;

        case 9:
            system("CLS");
            break;
        default:
            cout << translations["wrong_choice"] << "\n";
        }
        if (!isdigit(choice))
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        int numericChoice = choice - '0';
    } while (choice != 5);

    return 0;
}
