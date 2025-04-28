import kotlin.math.max
import kotlin.math.min

class CountFairPairs {
    /**
     * 在有序列表中找到第一个 >= target 的元素索引
     * @param list 已排序的列表（升序）
     * @param target 目标值
     * @return 第一个 >= target 的索引，若所有元素 < target 则返回 list.size
     */
    fun <T : Comparable<T>> lowerBound(list: List<T>, target: T): Int {
        var left = 0
        var right = list.size
        while (left < right) {
            val mid = (left + right) / 2
            if (list[mid] < target) {
                left = mid + 1
            } else {
                right = mid
            }
        }
        return left
    }
    /**
     * 在有序列表中找到第一个 > target 的元素索引
     * @param list 已排序的列表（升序）
     * @param target 目标值
     * @return 第一个 > target 的索引，若所有元素 ≤ target 则返回 list.size
     */
    fun <T : Comparable<T>> upperBound(list: List<T>, target: T): Int {
        var left = 0
        var right = list.size
//        println("list = ${list}")
        while (left < right) {
            val mid = (left + right) / 2
            if (list[mid] <= target) { // 注意此处条件与 lowerBound 不同
                left = mid + 1
            } else {
                right = mid
            }
//            println("target = ${target}, mid = ${mid}, left = ${left}, right = ${right}")
        }
        return left
    }
    fun countFairPairs(nums: IntArray, lower: Int, upper: Int): Long {
        val list = nums.sorted()
//        println(list)
        var ans = 0L
        for (i in nums.indices) {
            var pos1: Int = lowerBound(list, lower - list[i])
//            var pos1 = nums.binarySearch(lower - nums[i])
            var pos2: Int = upperBound(list, upper - list[i])
//            println("original: list[$i] = ${list[i]}, pos1 =  ${pos1}, pos2 = ${pos2}, ans = ${ans}")
//            if (pos1 < 0) pos1 = -pos1 - 1
            pos1 = max(pos1, i + 1)
//            if (pos2 < 0) pos2 = -pos2 - 1
            if (pos2 <= i)
                break
            ans += pos2 - pos1
//            println("i = $i, pos1 =  ${pos1}, pos2 = ${pos2}, ans = ${ans}")
        }
        return ans
    }
    fun readline_int(): IntArray =(readLine()!!.split(",").map{it.toInt()}).toIntArray()
    fun readInts() = readLine()!!.split(" ").map { it.toInt() }
};



fun main(args: Array<String>): Unit {
    val solution = CountFairPairs()
    val nums = solution.readline_int()
    val (lower, upper) = solution.readInts()
    println(solution.countFairPairs(nums, lower, upper))
}