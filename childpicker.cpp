#ifndef __MAC__
#include <GL/glew.h>
#endif

#include "ChildPicker.h"
#include "uniforms.h"

using namespace std;

ChildPicker::ChildPicker(shared_ptr<SgRbtNode> parent) {
    parent_ = parent;
}

bool ChildPicker::visit(SgTransformNode& node) {
    shared_ptr<SgNode> nodePtr = node.shared_from_this();
    
    // If only the parent is in the stack, this node is a child
    if (nodeStack_.size() == 1) {
        shared_ptr<SgRbtNode> asRbtNode = dynamic_pointer_cast<SgRbtNode>(nodePtr);
        children_.push_back(asRbtNode);
    }
    nodeStack_.push_back(nodePtr);
    return true;
}

bool ChildPicker::postVisit(SgTransformNode& node) {
    nodeStack_.pop_back();
    return true;
}

bool ChildPicker::visit(SgShapeNode& node) {
    return true;
}

bool ChildPicker::postVisit(SgShapeNode& node) {
    return true;
}

vector<shared_ptr<SgRbtNode>> ChildPicker::getChildren() {
    return children_;
}