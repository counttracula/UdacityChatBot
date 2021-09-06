#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    // removed delete _chatBot;
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge* edge)
{
    _parentEdges.emplace_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.emplace_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere (ChatBot* chatbot) {
    // std::cout << "Moving ChatBot at " << chatbot << std::endl;
    _chatBot = chatbot;
    // std::cout << "Done moving ChatBot pointing to " << _chatBot << ". Current node " << this << std::endl;
    // _chatBot->SetRootNode(this);
    _chatBot->SetCurrentNode (this);
    // std::cout << "Set current node to " << this << std::endl;
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

std::unique_ptr<GraphEdge>& GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index];

    ////
    //// EOF STUDENT CODE
}