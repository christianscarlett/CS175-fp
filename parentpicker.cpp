#ifndef __MAC__
#include <GL/glew.h>
#endif

#include "ParentPicker.h"
#include "uniforms.h"

using namespace std;

ParentPicker::ParentPicker(shared_ptr<SgRbtNode> child) {
    child_ = child;
}

bool ParentPicker::visit(SgTransformNode& node) {
    nodeStack_.push_back(node.shared_from_this());
    if (node == *child_) {
        shared_ptr<SgRbtNode> asRbtNode =
            dynamic_pointer_cast<SgRbtNode>(nodeStack_.at(1));
        parent_ = asRbtNode;
        return false;
    }
    return true;
}

bool ParentPicker::postVisit(SgTransformNode& node) {
    nodeStack_.pop_back();
    return true;
}

bool ParentPicker::visit(SgShapeNode& node) {
    return true;
}

bool ParentPicker::postVisit(SgShapeNode& node) {
    return true;
}

shared_ptr<SgRbtNode> ParentPicker::getParent() {
    return parent_;
}