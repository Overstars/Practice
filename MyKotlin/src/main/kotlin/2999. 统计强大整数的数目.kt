import kotlin.math.min

class Solution2 {
    var s: String = ""
    var low: String = ""
    var high: String = ""
    var limit: Int = 0
    var memory = Array<Long> (100) {-1}
    var diff: Int = 0
    fun dfs(pos: Int, limitLow:Boolean, limitHigh: Boolean):Long {
        if (pos == s!!.length) {
            return 1
        }
        if (!limitLow && !limitHigh && memory[pos] != -1L) {
            return memory[pos]
        }
        var ans = 0L
        val l = if (limitLow) low[pos] - '0' else 0
        val h = if (limitHigh) high[pos] - '0' else 9
        if (pos < diff) {
            // 可以任意枚举枚举下一位
            for (i in l .. min(h, limit)) {
                ans += dfs(pos + 1, limitLow && i == l, limitHigh && i == h)
            }
        } else {

            // 按照s依次枚举下一位
            val x = s[pos - diff] - '0'
            if (l <= x && x <= min(h, limit)) {
                ans = dfs(pos + 1, limitLow && x == l, limitHigh && x == h)
            }
        }

        //记忆化
        if (!limitLow && !limitHigh) {
            memory[pos] = ans
        }
        return ans
    }
    fun numberOfPowerfulInt(start: Long, finish: Long, limit: Int, s: String): Long {
        var ans = 0L
        this.s = "$s"
        this.high = "$finish"
        this.low = "$start"
        this.diff = this.high.length - this.low.length
        this.low = String(CharArray(this.diff, ){'0'}) + this.low
        this.limit = limit

        return dfs(0, true, true)
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toLong() }
fun main(args: Array<String>): Unit {
    val solution = Solution2()
    val (st, ed) = readInts()
    val limit = readLine()!!.toInt()
    val s = readLine()!!
    println(solution.numberOfPowerfulInt(st, ed, limit, s))
}