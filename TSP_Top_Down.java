  static int INF = (int)1e9;  
	static int V;
	static int cost [][];
	
	static int Top_Down_TSP (int pos , int mask) {
		if (mask == (1 << V) - 1) 
			return cost[pos][0]; // return to the start position
		
		int min = INF;
		for (int nxt = 0 ; nxt < V ; ++nxt)
			if (nxt != pos && ((mask) & nxt) == 0)
				min = Math.min(min, cost[pos][nxt] + Top_Down_TSP(nxt, mask | (1 << nxt)));
		return min;
	}
