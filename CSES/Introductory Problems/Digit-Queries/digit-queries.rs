use std::{fmt::Write, io::Read};

fn getdigit(num: u128, n: u128) -> u128 {
    let mut r;
    r = num / (10u128.pow(n as u32));
    r %= 10;
    r
}

fn solution(mut n: u128) -> u128 {
    if n < 10 {
        return n;
    }

    let mut num_digits: u32 = 1;
    let mut adder: u128 = 9;
    let compare = n;

    // get number of digits, and proper "region" offset
    let mut i = 0;
    loop {
        if i > compare {
            break;
        }

        i += adder;
        n += 10u128.pow(num_digits - 1);

        // adder = 9*1 -> 90*2 -> 900*3 -> 9000*4 -> ...
        adder = 9 * 10u128.pow(num_digits) * (num_digits + 1) as u128;
        num_digits += 1;
    }
    n -= 1;
    num_digits -= 1;
    let which_digit: u32 = (n % (num_digits) as u128) as u32;

    // get number
    n /= num_digits as u128;

    // get digit
    getdigit(n, (num_digits - 1 - which_digit) as u128)
}

fn main() {
    let mut read = String::with_capacity(1000);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let mut numbers = read
        .split_ascii_whitespace()
        .map(|x| x.parse::<u128>().unwrap());
    let num_tests = numbers.next().unwrap() as usize;
    let mut write = String::with_capacity(num_tests << 2);
    for _ in 0..num_tests {
        let n = numbers.next().unwrap();
        writeln!(write, "{}", solution(n)).unwrap();
    }
    print!("{}", write);
}
