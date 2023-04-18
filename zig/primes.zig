const std = @import("std");
const warn = std.debug.warn;

pub fn printPrimes(limit: usize) void {
    var primes: [limit + 1]bool = undefined;
    primes[0] = false;
    primes[1] = false;

    for (i: usize = 2; i <= limit; i += 1) : (primes[i] = true) {}

    for (i: usize = 2; i * i <= limit; i += 1) {
        if (primes[i]) {
            for (j: usize = i * i; j <= limit; j += i) : (primes[j] = false) {}
        }
    }

    for (i: usize = 2; i <= limit; i += 1) {
        if (primes[i]) {
            warn("{}\n", .{i});
        }
    }
}

pub fn main() !void {
    printPrimes(1000000);
    return .Ok;
}
