class Solution {
    fun canBeValid(s: String, locked: String): Boolean {
        var ans = true
        var total = 0
        var left = 0
        var right = 0
        val len = s.length
        if (len % 2 == 1)
            ans = false
        for (i in 0 until len) {
            if (locked[i] == '0')
                total++
            else {
                if (s[i] == '(')
                    left++
                else
                    right++
            }
            if (left + total < right)
                ans = false
        }
        left = 0
        right = 0
        total = 0
        for(i in len - 1 downTo 0) {
            if (locked[i] == '0')
                total++
            else {
                if (s[i] == '(')
                    left++
                else
                    right++
            }
            if (right + total < left)
                ans = false
        }
        return ans
    }

}

fun main(args: Array<String>): Unit {
    val str = readLine()!! // 读入一行字符串
    val locked = readLine()!! // 读入一行字符串
    val solution = Solution()
    println(solution.canBeValid(str, locked))
}