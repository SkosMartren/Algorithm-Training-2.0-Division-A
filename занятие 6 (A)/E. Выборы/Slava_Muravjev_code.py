def read_int():
    return int(input())


def read_ints():
    return map(int, input().split())


# decreased order
def upper_bound(values, key):
    left, right = -1, len(values)
    # values[left] >= key > values[right]
    while left + 1 < right:
        mid = (left + right) // 2
        if key > values[mid]:
            right = mid
        else:
            left = mid

    return right


n = read_int()
parties = [list(read_ints()) for _ in range(n)]

votes = [vote for vote, penalty in parties]
sorted_votes = list(reversed(sorted(votes)))

prefix_sums = [0] * (n + 1)
for i in range(n):
    prefix_sums[i + 1] = prefix_sums[i] + sorted_votes[i]

# max_n * max_vote + max_penalty
best_answer, best_index = 1e5 * 1e6 + 1e6 + 1, -1
for index, party in enumerate(parties):
    vote, penalty = party
    if -1 == penalty:
        continue

    def can_win(total_vote):
        decreased_count = upper_bound(sorted_votes, total_vote)
        # we found first smaller - it is count of greater or equal
        if total_vote == vote:
            decreased_count -= 1

        total_more = prefix_sums[decreased_count]
        min_acceptable = total_vote - 1

        need_decrease = total_more - (min_acceptable * decreased_count)
        decreased = total_vote - vote

        # if decreased < need_decreased:
        # we got less votes for ourself than took from opponents - FAIL
        return decreased >= need_decrease

    left_vote, right_vote = vote - 1, prefix_sums[-1]
    # left_vote not possible, right_vote possible
    while left_vote + 1 < right_vote:
        mid_vote = (left_vote + right_vote) // 2

        if can_win(mid_vote):
            # mid_vote - vote >= necessary decrease - OK
            right_vote = mid_vote
        else:
            left_vote = mid_vote

    answer = right_vote - vote + penalty
    if best_answer > answer:
        best_answer, best_index = answer, index

best_vote, best_penalty = parties[best_index]
best_delta = (best_answer - best_penalty)
best_vote += best_delta

votes[best_index] = best_vote

# always decrease greater or equal
for index in range(n):
    if index == best_index:
        continue

    need_decrease = max(0, votes[index] - (best_vote - 1))
    delta = min(best_delta, need_decrease)
    best_delta -= delta
    votes[index] -= delta

# optionally decrease any if needed more votes
for index in range(n):
    if index == best_index:
        continue

    delta = min(best_delta, votes[index])
    best_delta -= delta
    votes[index] -= delta

print(best_answer)
print(best_index + 1)
print(*votes)
