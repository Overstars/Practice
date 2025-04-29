import java.util.*

class NumRabbits {
    fun numRabbits(answers: IntArray): Int {
        var ans :Int = 0
        // 如果回答 x 的数量每次超过了 x + 1只，那么就拆分一个群体
        var mp :MutableMap<Int,Int> = mutableMapOf()
        for (i in answers) {
            mp[i] = (mp[i]?:0)+1
        }
        for ((k, v) in mp) {
            ans += (v + k) / (k + 1) * (k + 1)
        }
        return ans
    }
}
private fun readInts() = readLine()!!.split(" ").map { it.toLong() }
fun main(args: Array<String>): Unit {
    
}