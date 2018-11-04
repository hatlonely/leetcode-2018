# ！usr/bin/env python3


class RecentCounter:

    def __init__(self):
        self.ts = []

    def ping(self, t):
        i = 0
        while i < len(self.ts):
            if t - self.ts[i] <= 3000:
                break
            i += 1
        self.ts = self.ts[i:]
        self.ts.append(t)
        return len(self.ts)


if __name__ == '__main__':
    rc = RecentCounter()
    print(rc.ping(1), 1)
    print(rc.ping(100), 2)
    print(rc.ping(3001), 3)
    print(rc.ping(3002), 3)
    print(rc.ping(9000), 1)
