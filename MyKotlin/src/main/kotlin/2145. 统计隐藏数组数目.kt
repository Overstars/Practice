import kotlin.math.max
import kotlin.math.min

class NumberOfArrays {
    fun numberOfArrays(differences: IntArray, lower: Int, upper: Int): Int {
        var ans: Int = 0
        val list: List<Int> = differences.toList()
        var sum: Long = 0
        var recMin: Long = 0
        var recMax: Long = 0
        for (i in list.indices) {
            sum += list[i]
            recMin = min(recMin, sum)
            recMax = max(recMax, sum)
        }
        if (recMax - recMin > upper - lower) {
            ans = 0
        } else {
            ans = (upper - lower + 1 - (recMax - recMin)).toInt()
        }
        return ans
    }
}