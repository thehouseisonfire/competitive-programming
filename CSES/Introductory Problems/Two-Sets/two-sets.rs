use std::io::BufRead;
use std::io::Write;
use std::writeln;

fn sum(n: u64) -> u64 {
    (n * n + n) >> 1
}

fn main() {
    let mut reader = std::io::stdin().lock();
    let mut writer = std::io::stdout().lock();
    let mut buf = String::new();
    reader.read_line(&mut buf).unwrap();
    let n: u64 = buf.trim().parse().unwrap();
    let sum: u64 = sum(n);
    if sum % 2 == 1 {
        writeln!(writer, "NO").unwrap();
        return;
    }
    writeln!(writer, "YES").unwrap();
    let sum = sum >> 1;

    let mut counter = 1;
    let mut first_set_counter = sum;
    let mut i = n;
    while i < first_set_counter {
        first_set_counter -= i;
        i -= 1;
        counter += 1;
    }
    writeln!(writer, "{counter}").unwrap();

    let mut first_set_counter = sum;
    let mut i = n;
    while i < first_set_counter {
        first_set_counter -= i;
        write!(writer, "{i} ").unwrap();
        i -= 1;
    }
    writeln!(writer, "{first_set_counter}").unwrap();

    writeln!(writer, "{}", n - counter).unwrap();
    while 0 < i {
        if i != first_set_counter {
            write!(writer, "{i} ").unwrap();
        }
        i -= 1;
    }
    writeln!(writer, "").unwrap();
}
