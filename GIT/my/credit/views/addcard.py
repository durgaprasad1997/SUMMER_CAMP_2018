from django.views import View
from django.shortcuts import render,get_object_or_404,redirect
from credit.models import creditcard
from django.views.generic import ListView,DetailView,CreateView,DeleteView,UpdateView
from credit.forms.credit_form import *

from django.urls import *
from django.contrib.auth.mixins import LoginRequiredMixin,PermissionRequiredMixin
from credit.forms import credit_form


class CardView(LoginRequiredMixin,View):


    login_url = 'credit:login'
    def get(self,request,*args,**kwargs):

        credit = creditcard.objects.values('id','friendly_name','cardname','cvv','cardtype','cardnumber','expiry').order_by('cardname')

        pass

        return render(
            request,

            template_name='credit.html',
            context = {
                'credit': credit,
                'user_permissions': self.request.user.get_all_permissions
            }
        )


# class CardListView(LoginRequiredMixin,ListView):
#     login_url = 'credit:login'
#     model=creditcard
#     #context_object_name='creditlist'
#     template_name = 'credit.html'
#
#     def get_context_data(self, *, object_list=None, **kwargs):
#         c = super(CardListView, self).get_context_data(**kwargs)
#
#         return c
#     # def get_context_data(self, object_list=None, **kwargs):
#     #     context = super(CardListView, self).get_context_data(**kwargs)
#     #     context.update(
#     #         {
#     #             'creditlist': creditcard.objects.values('id','friendly_name','cardname','cvv','cardtype','cardnumber','expiry').filter(cardname=self.request.user.username)
#     #
#     #         }
#     #     )
#     #     return context



class CreateCreditView(LoginRequiredMixin,CreateView):

    login_url = 'credit:login'
    model = creditcard
    form_class = CreateCredit
    template_name = 'credit_form.html'
    success_url = reverse_lazy('credit:credit')





class UpdateCreditView(LoginRequiredMixin,UpdateView):

    login_url = 'credit:login'
    model = creditcard
    form_class = CreateCredit
    template_name = 'update_credit.html'
    success_url = reverse_lazy('credit:credit')



class DeleteCreditView(LoginRequiredMixin,DeleteView):

    login_url = 'credit:login'
    model=creditcard
    template_name="delete_credit.html"
    success_url=reverse_lazy('credit:credit')