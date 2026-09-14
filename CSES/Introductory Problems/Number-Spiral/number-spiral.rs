use std::cmp::max;
use std::fmt::Write;
use std::io::Read;

fn solution(row: u64, col: u64) -> u64 {
    match (row < col, max(row, col) % 2 == 0) {
        (true, true) => (col - 1) * (col - 1) + row,
        (true, false) => col * col + 1 - row,
        (false, true) => row * row + 1 - col,
        (false, false) => (row - 1) * (row - 1) + col,
    }
}

fn main() {
    let mut input = String::with_capacity(1000);
    let mut output = String::with_capacity(1000);
    std::io::stdin().lock().read_to_string(&mut input).unwrap();
    let mut numbers = input.split_ascii_whitespace().map(|x| x.parse().unwrap());
    let n = numbers.next().unwrap();
    for _ in 0..n {
        let n1 = numbers.next().unwrap();
        let n2 = numbers.next().unwrap();
        writeln!(output, "{}", solution(n1, n2)).unwrap();
    }
    print!("{output}");
}
