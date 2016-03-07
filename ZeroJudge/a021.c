#include <stdio.h>
#include <string.h>

struct BigNumber
{
	int arr[501];
	int sign;
	int length;
};

static struct BigNumber multi[10];

void set_value(struct BigNumber *num, char buf[501])
{
	int len = strlen(buf);
	int i;
	
	num->length = strlen(buf);
	num->sign = 0;

	for (i = 0; i < len; i++)
		num->arr[i] = buf[len-i-1] - '0';
	for ( ; i < 501; i++)
		num->arr[i] = 0;
}

void print_value(struct BigNumber num)
{
	int i = num.length;

	if (num.sign && !(num.length==1 && num.arr[0]==0))
		putchar('-');

	while (--i>=0)
		printf("%d", num.arr[i]);
	putchar('\n');
}

int compare(struct BigNumber *A, struct BigNumber *B)
{
	int i;
	if (A->length > B->length)
		return 1;
	if (A->length < B->length)
		return -1;

	i = A->length;

	while (--i >=0)
	{
		if (A->arr[i] > B->arr[i])
			return 1;
		if (A->arr[i] < B->arr[i])
			return -1;
	}
	return 0;
}

struct BigNumber add(struct BigNumber *A, struct BigNumber *B)
{
	struct BigNumber result;
	int i;

	set_value(&result, "");
	result.length = A->length >= B->length ? A->length : B->length;

	for (i = 0; i < result.length; i++)
	{
		result.arr[i] = A->arr[i] + B->arr[i];
		result.arr[i+1] = result.arr[i] / 10;
		result.arr[i] %= 10;
	}
	if (result.arr[i])
		result.length++;

	return result;
}

struct BigNumber sub(struct BigNumber *A, struct BigNumber *B)
{
	struct BigNumber result;
	struct BigNumber *ptr;
	int i = compare(A, B);

	set_value(&result, "");

	if (i == 0)
	{
		result.length = 1;
		result.arr[0] = 0;
		return result;
	}

	if (i < 0)
	{
		ptr = A;
		A = B;
		B = ptr;
		result.sign = 1;
	}
	result.length = A->length;

	for (i = 0; i < result.length; i++)
		result.arr[i] = A->arr[i] - B->arr[i];

	for (i = 0; i < result.length; i++)
	{
		if (result.arr[i] < 0)
		{
			result.arr[i] += 10;
			result.arr[i+1]--;
		}
	}

	if (!result.arr[result.length-1])
		result.length--;

	return result;
}

void mul_10(struct BigNumber *num)
{
	int i;

	if (num->length == 1 && num->arr[0] == 0)
		return;
	for (i = num->length; i > 0; i--)
		num->arr[i] = num->arr[i-1];
	num->arr[0] = 0;
	num->length++;
}

void mul_scale(struct BigNumber *src, struct BigNumber *dst, int scale, int do_carry)
{
	int i;
	if (dst->length)
		set_value(dst, "");

	if (scale == 1)
	{
		for (i = 0; i < src->length; i++)
			dst->arr[i] = src->arr[i];
		dst->length = src->length;
		return;
	}

	for (i = 0; i < src->length; i++)
		dst->arr[i] = src->arr[i] * scale;

	if (do_carry)
	{
		for (i = 0; i < src->length; i++)
		{
			dst->arr[i+1] += dst->arr[i] / 10;
			dst->arr[i] %= 10;
		}
	}
	dst->length = dst->arr[i] ? i+1 : i;
}

struct BigNumber mul(struct BigNumber *A, struct BigNumber *B)
{
	struct BigNumber result;
	struct BigNumber *multi_ptr[10];
	struct BigNumber *ptr;
	int i, j, k;

	if (A->length == 1 && A->arr[0] == 0)
		return *A;
	if (B->length == 1 && B->arr[0] == 0)
		return *B;
	if (A->length == 1 && A->arr[0] == 1)
		return *B;
	if (B->length == 1 && B->arr[0] == 1)
		return *A;

	set_value(&result, "");

	if(compare(A, B) < 0)
	{
		ptr = A;
		A = B;
		B = ptr;
	}

	for (i=0; i<10; i++)
		multi_ptr[i] = 0;

	multi_ptr[1] = A;

	for (i = 0; i < B->length; i++)
	{
		if (k = B->arr[i])
		{
			if (!multi_ptr[k])
			{
				set_value(&multi[k], "");
				mul_scale(A, &multi[k], k, 0);
				multi_ptr[k] = &multi[k];
			}

			for (j=0; j<A->length; j++)
				result.arr[j+i] += multi_ptr[k]->arr[j];
		}
	}

	result.length = A->length + B->length - 1;
	for (i = 0; i < result.length; i++)
	{
		result.arr[i+1] += result.arr[i] / 10;
		result.arr[i] %= 10;
	}
	result.length = result.arr[i] ? i+1 : i;
	return result;
}

struct BigNumber div(struct BigNumber *A, struct BigNumber *B)
{
	struct BigNumber result;
	struct BigNumber dividend, tmp;
	int i, j;

	if (A->length == 1 && A->arr[0] == 0)
		return *A;
	if (B->length == 1 && B->arr[0] == 1)
		return *A;

	set_value(&result, "");
	i = compare(A, B);
	if (i == 0)
	{
		result.length = 1;
		result.arr[0] = 1;
		return result;
	}
	else if (i < 0)
	{
		result.length = 1;
		return result;
	}

	set_value(&dividend, "0");
	for (i = A->length - 1; i>=0; i--)
	{
		mul_10(&dividend);
		dividend.arr[0] = A->arr[i];

		if (dividend.length < B->length)
			continue;
		for (j = 9; j > 0; j--)
		{
			mul_scale(B, &tmp, j, 1);
			if (compare(&dividend, &tmp) >= 0)
			{
				dividend = sub(&dividend, &tmp);
				result.arr[i] = j;
				break;
			}
		}
	}
	for (i = A->length - 1; !result.arr[i]; i--)
	{
		/* do nothing */
	}
	result.length = i + 1;
	return result;
}

int main(void)
{
	struct BigNumber A, B;
	char buffer[501];
	char op;

	while (scanf("%s", buffer)!=EOF)
	{
		set_value(&A, buffer);
		scanf("%s", buffer);

		op = buffer[0];

		scanf("%s", buffer);
		set_value(&B, buffer);

		switch(op)
		{
		case '+':
			print_value(add(&A, &B));
			break;
		case '-':
			print_value(sub(&A, &B));
			break;
		case '*':
			print_value(mul(&A, &B));
			break;
		case '/':
			print_value(div(&A, &B));
			break;
		}
	}
	return 0;
}
