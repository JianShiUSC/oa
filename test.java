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
        }

        for(Connection c : connections) {
            if(union(c.node1, c.node2, map)) {
                result.add(c);
            }
        }
        if(set.size()-1 != result.size()) return null;
        Collections.sort(result, NameComparator);
        return result;
	}

    private static bool union(String a, String b, Map<String, String> map) {
        String aRoot = find(a, map);
        String bRoot = find(b, map);
        if(aRoot.equals(bRoot)) return false;
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
}
