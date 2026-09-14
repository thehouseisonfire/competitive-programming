use std::{fmt::Write, io::Read};

fn main() {
    let mut read = String::with_capacity(1000);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let mut numbers = read
        .split_ascii_whitespace()
        .map(|x| x.parse::<i32>().unwrap());
    let n = numbers.next().unwrap();
    let mut write = String::with_capacity(n as usize * 4);
    for _ in 0..n {
        let x = numbers.next().unwrap();
        let y = numbers.next().unwrap();
        if (x + y) % 3 == 0 && x - y <= y && y - x <= x {
            writeln!(write, "YES").unwrap();
        } else {
            writeln!(write, "NO").unwrap();
        }
    }
    print!("{}", write);
}
