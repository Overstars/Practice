import kotlin.math.max

class ClosestMeetingNode {
    val inf: Int = Int.MAX_VALUE
    fun dfs(dist: IntArray, edges: IntArray, st: Int, len: Int) {
        if (st == -1 || dist[st] != inf)
            return
        dist[st] = len
        dfs(dist, edges, edges[st], len + 1)
    }
    fun getDist(edges: IntArray, st: Int, size: Int): IntArray {
        val dist = IntArray(size) { inf }
        dfs(dist, edges, st, 0)
        return dist
    }

    fun closestMeetingNode(edges: IntArray, node1: Int, node2: Int): Int {
        var ans: Int = -1
        val dist1 = getDist(edges, node1, edges.size + 1)
        val dist2 = getDist(edges, node2, edges.size + 1)
        for (i in 0 until edges.size + 1) {
            if (dist1[i] != inf && dist2[i] != inf) {
                if (ans == -1 || max(dist1[i], dist2[i]) < max(dist1[ans], dist2[ans])) {
                    ans = i
                }
            }
        }

        return ans
    }
}