impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut left = 0; // left pointer

        for right in 0..nums.len() { // right pointer
            if nums[right] != 0 {
                nums.swap(left, right);
                left += 1;
            }
        }
    }
}
