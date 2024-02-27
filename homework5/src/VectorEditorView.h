//
// Created by Lina1 on 26.02.2024.
//
#pragma once

#include <memory>

#include "Models/VectorDocument.h"


class VectorEditorView : public std::enable_shared_from_this<VectorEditorView> {

    VectorDocument _model;

public:

    explicit VectorEditorView(VectorDocument model)
    {
        _model = model;
        _model.view = shared_from_this();
    }



};

