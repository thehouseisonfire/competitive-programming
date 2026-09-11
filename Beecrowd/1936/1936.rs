fn unique_lower_bound(target: i64, vec: &[i64]) -> Option<&i64> {
    let mut left = 0;
    let mut right = vec.len();
    while left < right {
        let mid = left + (right - left) / 2;
        let cmp = *vec.get(mid)?;
        if target >= cmp {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    vec.get(left - 1)
}

fn factorial(num: i64, results: &mut Vec<i64>) -> i64 {
    if let Some(i) = results.get(num as usize) {
        return *i;
    }
    let aux = num * factorial(num - 1, results);
    results.push(aux);
    *results.get(num as usize).unwrap()
}
fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let mut num: i64 = buf.trim().parse().unwrap();
    let mut results = Vec::with_capacity(100);
    results.push(0);
    results.push(1);
    results.push(2);
    factorial(10, &mut results);
    let mut fac_counter = 11;
    let mut counter = 0;
    while 0 < num {
        while unique_lower_bound(num, &results).is_none() {
            factorial(fac_counter, &mut results);
            fac_counter += 5;
        }
        num -= unique_lower_bound(num, &results).unwrap();
        counter += 1;
    }
    println!("{}", counter);
}
