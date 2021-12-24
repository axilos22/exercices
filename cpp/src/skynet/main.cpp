#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
        int next_node_rank;
        bool gateway;
        bool next;
    public:
        Node(): gateway(false), next(false) {};
        void attachNext(int rank) {
            next = true;
            next_node_rank=rank;
        }
        void detachNext() {
            next = false;
        }
        int getNext() {
            if(next)
                return next_node_rank;
            else
                return -1;
        }
        void declareGateway() {gateway = true;}
        bool isGateway() {return gateway;}
        bool hasNext() {return next;}
};

vector<Node> nodes;

int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    for(int n = 0; n < N; n++) {
        //cerr << "Creadted Node #" << n << endl;
        nodes.push_back(Node());
    }
    //cerr << "nodes is size of " << nodes.size() << endl;
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        nodes.at(N1).attachNext(N2);
        cerr << "Node #" << N1 << " and " << N2 << " are attached" << endl;
        //cerr << "The attached node to node " << N1 << " is Node " << nodes.at(N1).getNext() << endl;
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        nodes.at(EI).declareGateway();
        //cerr << "Node #" << EI << " is the gateway" << endl;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        cerr << "Agent node is " << SI << endl;

        int rank1, rank2;
        for(int rank=0; rank<nodes.size(); rank++) {
            cerr << "Evaluating " << rank << endl;
            if(nodes.at(rank).hasNext()) {
                //find gateway and its neighboor
                if(nodes.at(rank).isGateway()){
                    rank1 = rank;
                    rank2 = nodes.at(rank1).getNext();
                }
                //find a node whose next is a gateway
                int next_rank = nodes.at(rank).getNext();
                if(nodes.at(next_rank).isGateway()) {
                    rank1 = rank;
                    rank2 = next_rank;
                }
            }  
        }
        string answer = to_string(rank1)+" "+to_string(rank2);
        nodes.at(rank1).detachNext();
        cerr << "Answer= "<< answer << endl;
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << answer << endl;
    }
}