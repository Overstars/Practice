import java.util.*
import kotlin.math.max

class Solution6 {
    fun countGood(nums: IntArray, k: Int): Long {
        var ans = 0L
        var cnt = 0L
        var mp:MutableMap<Int,Int> = mutableMapOf()
        var l = 0
        var r = -1
        for (l in nums.indices) {
            while (r < nums.size && cnt < k) {
                r++
                if (r >= nums.size)
                    break
                cnt += mp[nums[r]]?:0
                mp[nums[r]] = (mp[nums[r]]?:0) + 1
            }
            if (cnt >= k && r < nums.size) {
                ans += nums.size - r
            }
            cnt -= max(0, mp[nums[l]]!! - 1)
            mp[nums[l]] = (mp[nums[l]]?:0) - 1
//            println("l = $l r = $r cnt = $cnt ans = $ans")
        }
        for (i in mp.keys) {
            ans += mp[i]!! * (mp[i]!! - 1) / 2
        }
        return ans
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toInt() }

fun main(args: Array<String>): Unit {

}