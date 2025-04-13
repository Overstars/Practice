class Solution4 {
    val mod = 1000000007

    fun qpow(base: Long, exp: Long): Long {
        var ans = 1L
        var x = base % mod
        var exp = exp
        while (exp > 0) {
            if (exp % 2 == 1L) {
                ans = (ans * x) % mod
            }
            x = (x * x) % mod
            exp /= 2
        }
        return ans
    }

    fun countGoodNumbers(n: Long): Int {
        var ans = 0L
//        if (n > 1 && n % 2 == 0L)
//            ans = (qpow(5, n /2 ) * qpow(4, n / 2) %mod) * 4 % mod
//        else
        ans = (qpow(5, (n + 1) / 2) * qpow(4, n / 2)) % mod
        return ans.toInt()
    }
}

private fun readInts() = readLine()!!.split(" ").map { it.toLong() }

fun main(args: Array<String>): Unit {
    val (n) = readInts()
    val solution = Solution4()
    println(solution.countGoodNumbers(n))
}