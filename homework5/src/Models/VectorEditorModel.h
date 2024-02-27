//
// Created by Lina1 on 26.02.2024.
//
#pragma once

#include "VectorDocument.h"

#include "../VectorEditorView.h"
#include "./GrapthPrimitives/Line.h."
#include "GrapthPrimitives/Rectangle.h"

class VectorEditorModel {

    std::shared_ptr<VectorEditorView> _view;
    std::shared_ptr<VectorDocument> _document;
public:
    void setActiveDocument(std::shared_ptr<VectorDocument> document)
    {
        _document = document;
    }

    std::shared_ptr<VectorDocument> getActiveDocument()
    {
        return _document;
    }

};

