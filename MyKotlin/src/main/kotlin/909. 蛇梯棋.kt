import kotlin.math.min

class SnakesAndLadders {
    var ans: Int = Int.MAX_VALUE
    fun dfs(st: Int, step: Int, board: Array<IntArray>) {
        if (st == board.size * board[0].size) {
            ans = min(ans, step)
        }
    }
    fun snakesAndLadders(board: Array<IntArray>): Int {
        val siz: Int = board.size * board[0].size
        val vis = BooleanArray(siz + 1) { false }
        val dp = IntArray(siz + 1) { -1 }
        return if (ans == Int.MAX_VALUE) -1 else ans
    }
}