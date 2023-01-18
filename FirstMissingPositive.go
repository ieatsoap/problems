func firstMissingPositive(nums []int) int {

	l_n := len(nums)

	if l_n == 1 {
		if nums[0] == 1 {
			return 2
		} else {
			return 1
		}
	}

	found := make([]int, l_n)
	max := 0

	for i, v := range nums {
		if v <= l_n && v > 0 {
			found[v-1] = -1
		}
		if found[i] != -1 {
			found[i] = i + 1
		}
		if v > max {
			max = v
		}
	}

	for _, v := range found {
		if v != -1 {
			return v
		}
	}

	return max + 1
}
