

class SortColors {
// 定义一个函数，用于对数组中的元素进行排序
    fun sortColors(nums: IntArray): Unit {
        // 创建一个Map，用于存储数组中每个元素出现的次数
        val map = HashMap<Int, Int>().apply {
            // 遍历数组中的每个元素
            for (i in nums) {
                // 将元素作为键，出现次数作为值，存入Map中
                put(i, getOrDefault(i, 0) + 1)
            }
        }
        // 遍历Map中的每个键值对
        var cnt: Int = 0
        for ((key, value) in map) {
            // 将键值对中的值作为次数，将键作为元素，添加到数组中
            for (i in 0 until value) {
                nums[cnt + i] = key
            }
            cnt += value
        }
    }
}