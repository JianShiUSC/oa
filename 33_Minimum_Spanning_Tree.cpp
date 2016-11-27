class Connection {
public:
    string node1;
    string node2;
    int cost;
    Connection(string a, string b, int c) {
        node1 = a;
        node2 = b;
        cost = c;
    }
};

class City_Connections {
public:
    static bool costComp(Connection* a, Connection* b) {
        return a->cost < b->cost;
    }

    static bool nameComp(Connection* a, Connection* b) {
        if(a->node1 == b->node1) {
            return a->node2 < b->node2;
        }
        return a->node1 < b->node1;
    }

    string find(string a, map<string, string>& mm) {
        while(a != mm[a]) {
            a = mm[a];
        }
        return a;
    }

    bool unionF(string a, string b, map<string, string>& mm) {
        string aRoot = find(a, mm);
        string bRoot = find(b, mm);
        if(aRoot == bRoot) return false;
        mm[bRoot] = aRoot;  // b连到a上
        return true;
    }

    vector<Connection*> getLowCost(vector<Connection*> connections) {
        vector<Connection*> res;
        set<string> ss;
        map<string, string> mm; // child to parent
        sort(connections.begin(), connections.end(), costComp);

        for(Connection* c : connections) {
            string cityA = c->node1;
            string cityB = c->node2;
            ss.insert(cityA);
            ss.insert(cityB);
            mm[cityA] = cityA;
            mm[cityB] = cityB;
        }

        for(Connection* c : connections) {
            // unionF return true means 从不同集合里联合到一起
            if(unionF(c->node1, c->node2, mm)) {
                res.push_back(c);
            }
        }
        if(ss.size() - 1 != res.size()) res.clear();
        sort(res.begin(), res.end(), nameComp);
        return res;
    }
};

int main() {
    vector<Connection*> connections;

    connections.push_back(new Connection("A","B",6));
    connections.push_back(new Connection("B","C",4));
    connections.push_back(new Connection("C","D",5));
    connections.push_back(new Connection("D","E",8));
    connections.push_back(new Connection("E","F",1));
    connections.push_back(new Connection("B","F",10));
    connections.push_back(new Connection("E","C",9));
    connections.push_back(new Connection("F","C",7));
    connections.push_back(new Connection("B","E",3));
    connections.push_back(new Connection("A","F",1));

    City_Connections sol;

    vector<Connection*> res = sol.getLowCost(connections);
    for (Connection* c : res){
        cout << c->node1 << "->" << c->node2 << " 需要花费大洋: " << c->cost << " ";
    }
    cout << endl;
}
