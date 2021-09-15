#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    // data handles (owned)
    // edges to subsequent nodes which are now exclusively owner by GraphNode
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;

    // data handles (not owned)
    std::vector<GraphEdge*> _parentEdges; // edges to preceding nodes

    // member variable rather than the pointer
    ChatBot _chatBot;

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge* GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }
    ChatBot* getChatBotHandle() { return &_chatBot; }
    void setChatBotHandle(ChatBot chatBot) { _chatBot = std::move(chatBot); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge* edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);
    void MoveChatbotHere(ChatBot chatbot);
    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */