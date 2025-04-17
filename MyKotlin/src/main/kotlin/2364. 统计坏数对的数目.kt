import java.util.*
import kotlin.math.max

class Solution8 {
    fun countBadPairs(nums: IntArray): Long {
        var ans = 0L
        val n:Long = nums.size.toLong()
        // 好pair : j - i = a[j] - a[i]
        // 等价于 i - a[i] = j - a[j]
        for (i in 0 until nums.size) {
            nums[i] -= i
        }
        val map = mutableMapOf<Int, Long>()
        for (i in nums.indices) {
            ans += map[nums[i]] ?: 0
            map[nums[i]] = (map[nums[i]] ?: 0) + 1
        }
        return n * (n - 1) / 2 - ans
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toInt() }

fun main(args: Array<String>): Unit {

}