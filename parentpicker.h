#ifndef PARENTPICKER_H
#define PARENTPICKER_H

#include <map>
#include <memory>
#include <stdexcept>
#include <vector>

#include "asstcommon.h"
#include "cvec.h"
#include "drawer.h"
#include "ppm.h"
#include "scenegraph.h"

class ParentPicker : public SgNodeVisitor {
    std::vector<shared_ptr<SgNode>> nodeStack_;
    shared_ptr<SgRbtNode> child_;
    shared_ptr<SgRbtNode> parent_;

public:
    ParentPicker(shared_ptr<SgRbtNode> child);

    virtual bool visit(SgTransformNode& node);
    virtual bool postVisit(SgTransformNode& node);
    virtual bool visit(SgShapeNode& node);
    virtual bool postVisit(SgShapeNode& node);

    shared_ptr<SgRbtNode> getParent();
};


#endif