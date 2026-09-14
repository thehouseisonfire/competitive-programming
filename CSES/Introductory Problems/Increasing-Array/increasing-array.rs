use std::io::{self, BufRead};

fn solution(arr: &[i64]) -> i64 {
    let mut iter = arr.iter();
    let mut last = iter.next().unwrap();
    let mut sum = 0;
    for i in iter {
        if i < last {
            sum += last - i;
        } else {
            last = i;
        }
    }
    sum
}

fn main() {
    let mut reader = io::stdin().lock();
    let mut buf = String::new();
    reader.read_line(&mut buf).unwrap();
    buf.clear();
    reader.read_line(&mut buf).unwrap();
    let numbers: Vec<i64> = buf
        .split_ascii_whitespace()
        .map(|s| s.parse().unwrap())
        .collect();
    println!("{}", solution(&numbers));
}
