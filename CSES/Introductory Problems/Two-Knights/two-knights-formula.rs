use std::{fmt::Write, io::Read};

fn solve(n: i64, write: &mut String) {
    for i in 1..=n {
        writeln!(write, "{}", (i * i * i * i - 9 * i * i + 24 * i - 16) >> 1).unwrap();
    }
}

fn main() {
    let mut read = String::with_capacity(16);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let n = read.trim().parse::<i64>().unwrap();
    let mut write = String::with_capacity(n as usize * 16);
    solve(n, &mut write);
    print!("{}", write);
}
