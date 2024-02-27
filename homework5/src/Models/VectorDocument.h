#pragma once

#include <string>
#include <memory>
#include <vector>

#include "IGraphPrimitive.h"
#include "Point.h"

/**
 * @class VectorDocument
 * @brief Represents a vector document.
 *
 * The VectorDocument class represents a vector document that can store and manipulate
 * a collection of graph elements. It provides functionality to import and export the document
 * from/to a file, add and remove graph elements, retrieve graph elements, draw the document,
 * select elements, and get element indices based on a point.
 *
 * @var std::string _filePath
 * The path of the file associated with the vector document.
 *
 * @var std::vector<std::shared_ptr<IGraphElement>> primitives
 * The collection of graph elements stored in the vector document.
 *
 * @var int _selectedItemIndex
 * The index of the selected graph element in the vector document. -1 means no element is selected.
 */
class VectorDocument {
    std::string _filePath;
    std::vector<std::shared_ptr<IGraphElement>> primitives;
    int _selectedItemIndex = -1;
public:

    VectorDocument() = default;


    explicit VectorDocument(std::string_view filePath)
    : _filePath(filePath)
    {

    };

    /**
     * @brief Imports a vector document from a file.
     *
     * This function imports a vector document from the specified file path. The file must be in a supported format
     * and contain valid graph elements. This function does not overwrite the current content of the vector document.
     *
     * @param filepath The path of the file to import from.
     */
    void importFromFile(const std::string &filepath) {}

    /**
     * @brief Exports the vector document to a file.
     *
     * This function exports the current vector document to the specified file path. The exported file will contain the graph
     * elements stored in the vector document. If the file already exists, its content will be overwritten.
     *
     * @param filepath The path of the file to export to.
     */
    void exportToFile(const std::string &filepath) {}

    /**
     * @brief Get the file path associated with the vector document.
     *
     * This function returns the file path associated with the vector document.
     *
     * @return std::string The file path.
     */
    std::string getFilepath()
    {
        return _filePath;
    };

    /**
     * @brief Adds a primitive graph element to the vector document.
     *
     * This function adds a primitive graph element to the vector document. The graph element is passed as a shared pointer
     * and is added to the collection of graph elements stored in the vector document.
     *
     * @param primitive The shared pointer to the primitive graph element to be added.
     * @return The index at which the primitive was added in the vector document.
     */
    int addPrimitive(std::shared_ptr<IGraphElement> primitive) {
        primitives.push_back(primitive);
        return primitives.size()-1;
    }

    /**
        * @brief Removes a primitive graph element from the vector document.
        *
        * This function removes a primitive graph element from the vector document at the specified index.
        * The index must be a valid index within the range of the primitives collection.
        *
        * @param index The index of the primitive graph element to be removed.
        */
    void removePrimitive(int index) {
        primitives.erase(primitives.begin() + index);
    }

    /**
     * @brief Retrieves a graph element from the vector document based on the specified index.
     *
     * This function returns a shared pointer to a graph element based on the specified index.
     * The index must be a valid index within the range of the primitives collection.
     *
     * @param index The index of the graph element to retrieve.
     * @return A shared pointer to the graph element.
     *
     * @note The function may return nullptr if the index is invalid or if there is no graph element at the specified index.
     */
    std::shared_ptr<IGraphElement> getPrimitive(int index)
    {
        return primitives[index];
    }

    /**
     * @brief Draws the vector document.
     *
     * This function iterates over each primitive graph element stored in the vector document and calls their respective draw() functions to draw them.
     * The draw() function is a pure virtual function defined in the IGraphElement interface, which ensures that each graph element must implement its own drawing logic.
     *
     * @note The function does not modify the vector document or its primitives. It is a const member function.
     */
    void drawDocument() const {
        for(const auto &primitive : primitives) {
            primitive->draw();
        }
    }


    /**
     * @brief Get the index of the currently selected graph element in the vector document.
     *
     * This function returns the index of the currently selected graph element in the vector document.
     * If no element is currently selected, it will return -1.
     *
     * @return int The index of the currently selected graph element, or -1 if no element is selected.
     */
    int getSelectedElementIndex()
    {
        return _selectedItemIndex;
    }

    /**
     * @brief Retrieves a graph element from the vector document based on the specified point.
     *
     * This function searches for a graph element in the vector document whose shape contains the specified point.
     * It iterates over each graph element stored in the vector document and checks if the point is contained within the shape of each element.
     *
     * @param point The point to search for a graph element.
     * @return A shared pointer to the graph element if found, otherwise nullptr.
     *
     * @note The function may return nullptr if no graph element is found within the specified point.
     */
    std::shared_ptr<IGraphElement> getElementIn(Point point) {
        auto index = getElementIndexIn(point);
        if (index != -1) {
                return primitives[index];
        }
        return nullptr;
    }

    /**
     * @brief Get the index of a graph element in the vector document based on a point.
     *
     * This function searches for a graph element in the vector document whose shape contains the specified point.
     * It iterates over each graph element stored in the vector document and checks if the point is contained within the shape of each element.
     *
     * @param point The point to search for a graph element.
     * @return The index of the found graph element if found, otherwise -1.
     *
     * @note The function returns -1 if no graph element is found within the specified point.
     */
    int getElementIndexIn(Point point){
        for (int i = 0; i < primitives.size(); i++) {
            if (primitives[i]->contains(point)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief Sets the selected item index.
     *
     * This function sets the index of the selected item in the list. The selected item index is used to keep track of the currently selected item for further operations or user interactions
    *.
     *
     * @param index The index of the item to be selected.
     */
    void setSelected(int index)
    {
        _selectedItemIndex = index;
    }


};

