
class Solution7 {
    fun countPairs(nums: IntArray, k: Int): Int {
        var ans = 0
        for (i in 0 until nums.size) {
             for (j in i + 1 until nums.size) {
                    if (nums[i] == nums[j] && i * j % k == 0) {
                        ans++
                    }
             }
        }
        return ans
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toInt() }

fun main(args: Array<String>): Unit {

}