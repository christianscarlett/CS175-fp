#ifndef CHILDPICKER_H
#define CHILDPICKER_H

#include <map>
#include <memory>
#include <stdexcept>
#include <vector>

#include "asstcommon.h"
#include "cvec.h"
#include "drawer.h"
#include "ppm.h"
#include "scenegraph.h"

class ChildPicker : public SgNodeVisitor {
    std::vector<shared_ptr<SgNode>> nodeStack_;
    std::vector<shared_ptr<SgRbtNode>> children_;
    shared_ptr<SgRbtNode> parent_;

public:
    ChildPicker(shared_ptr<SgRbtNode> parent);

    virtual bool visit(SgTransformNode& node);
    virtual bool postVisit(SgTransformNode& node);
    virtual bool visit(SgShapeNode& node);
    virtual bool postVisit(SgShapeNode& node);

    vector<shared_ptr<SgRbtNode>> getChildren();
};


#endif