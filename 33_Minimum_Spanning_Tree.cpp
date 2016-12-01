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





import java.util.*;

class Connection {
	String node1;
	String node2;
	int cost;
	public Connection(String a, String b, int c) {
		node1 = a;
		node2 = b;
		cost = c;
	}
}

public class CityConnections {
	public static ArrayList<Connection> getLowCost(ArrayList<Connection> connections) {
		ArrayList<Connection> result = new ArrayList<>();
		Set<String> set = new HashSet<>();
		Map<String, String> map = new HashMap<>();
		Collections.sort(connections, CostComparator);

		for(Connection c : connections) {
			String cityA = c.node1;
			String cityB = c.node2;
			set.add(cityA);
			set.add(cityB);
			map.put(cityA, cityA);
			map.put(cityB, cityB);
		}

		for(Connection c : connections) {
			if(union(c.node1, c.node2, map)) {
				result.add(c);
			}
		}
		if((set.size() - 1) != result.size()) {
			return null;
		}
		Collections.sort(result, NameComparator);
		return result;
	}

	private static boolean union(String a, String b, Map<String, String> map) {
		String aRoot = find(a, map);
		String bRoot = find(b, map);
		if(aRoot.equals(bRoot)) {
			return false;
		}
		map.put(bRoot, aRoot);
		return true;
	}

	private static String find(String a, Map<String, String> map) {
		if(a.equals(map.get(a))) {
			return a;
		}
		String parent = find(map.get(a), map);
		map.put(a, map.get(map.get(a)));
		return parent;
	}

	static Comparator<Connection> CostComparator = new Comparator<Connection>() {
		public int compare(Connection a, Connection b) {
			return a.cost - b.cost;
		}
	};

	static Comparator<Connection> NameComparator = new Comparator<Connection>() {
		public int compare(Connection a, Connection b) {
			if(a.node1.equals(b.node1)) {
				return a.node2.compareTo(b.node2);
			}
			return a.node1.compareTo(b.node1);
		}
	};

	public static void main(String[] args) {
	    ArrayList<Connection> connections = new ArrayList<>();
	    //这里还是一个苯环形状，有化学出身的看到这里可以鼓掌了
	    connections.add(new Connection("A","B",6));
	    connections.add(new Connection("B","C",4));
	    connections.add(new Connection("C","D",5));
	    connections.add(new Connection("D","E",8));
	    connections.add(new Connection("E","F",1));
	    connections.add(new Connection("B","F",10));
	    connections.add(new Connection("E","C",9));
	    connections.add(new Connection("F","C",7));
	    connections.add(new Connection("B","E",3));
	    connections.add(new Connection("A","F",1));

	    ArrayList<Connection> res = getLowCost(connections);
	    for (Connection c : res){
	        System.out.println(c.node1 + " -> " + c.node2 + " 需要花费大洋 : " + c.cost);
	    }
	}
}
