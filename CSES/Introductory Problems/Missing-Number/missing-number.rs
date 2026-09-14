use std::io::{self, BufRead};

fn solution(max: i64, numbers: &[i64]) {
    let sum = numbers.iter().sum::<i64>() - max;
    let gauss = (max.pow(2) - max) / 2;
    println!("{}", gauss - sum);
}

fn main() {
    let mut reader = io::stdin().lock();
    let mut line = String::new();
    reader.read_line(&mut line).unwrap();
    let n: i64 = line.trim().parse().unwrap();
    line = String::new();
    reader.read_line(&mut line).unwrap();
    let numbers: Vec<i64> = line
        .split_whitespace()
        .map(|v| v.parse::<i64>().unwrap())
        .collect();
    solution(n, &numbers);
}
