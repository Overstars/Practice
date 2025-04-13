class Solution3 {
    private fun isSymmetric(num: Int): Boolean {
        val s = num.toString()
        val len = s.length
        if (len % 2 == 1)
            return false
        var left = 0
        var right = 0
        for (i in 0 until len / 2) {
            left += s[i] - '0'
            right += s[len - i - 1] - '0'
        }
        return left == right
    }
// 定义一个函数，用于计算low到high之间的对称整数个数
    fun countSymmetricIntegers(low: Int, high: Int): Int {
        // 初始化计数器
        var ans: Int = 0
        // 遍历low到high之间的所有整数
        for (i in low..high) {
            // 如果当前整数是对称整数，则打印并计数
            if (isSymmetric(i)) {
                println(i)
                ans++
            }
        }
        // 返回计数结果
        return ans
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toInt() }

fun main(args: Array<String>): Unit {
    val (low, high) = readInts()
    val solution = Solution3()
    println(solution.countSymmetricIntegers(low, high))
}