use std::{fmt::Write, io::Read};

fn printbits(write: &mut String, x: u16, n_bits: u8) {
    for i in (0..n_bits).rev() {
        write.push(char::from(b'0' + ((x >> i) & 1) as u8));
    }
}

fn main() {
    let mut read = String::with_capacity(16);
    std::io::stdin().lock().read_to_string(&mut read).unwrap();
    let n = read.trim().parse::<u8>().unwrap();
    let mut write = String::with_capacity((1usize << n) * (n as usize + 1));
    for i in 0..(2u32 << (n - 1)) {
        printbits(&mut write, (i ^ (i >> 1)) as u16, n);
        writeln!(write).unwrap();
    }

    print!("{}", write);
}
